# $FreeBSD$

PORTNAME=	monitor-core
PORTVERSION=	3.7.1
CATEGORIES=	sysutils net
MASTER_SITES=	SF/ganglia/ganglia%20monitoring%20core/${PORTVERSION}
PKGNAMEPREFIX=	ganglia-
.if defined(CLUSTER)
PKGNAMESUFFIX=	-${CLUSTER}
.endif
DISTNAME=	ganglia-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Ganglia cluster monitor, monitoring daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libconfuse.so:devel/libconfuse \
		libpcre.so:devel/pcre \
		libexpat.so:textproc/expat2

OPTIONS_DEFINE=	GMETAD
OPTIONS_DEFAULT=	GMETAD
GMETAD_DESC=	include gmetad

USES=		libtool pkgconfig python:2.7

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-setuid=ganglia --enable-setgid=ganglia \
		--with-python=${PYTHON_CMD}
CONFIGURE_ENV=	GANGLIA_ACK_SYSCONFDIR=1
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS=		ganglia
GROUPS=		ganglia

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

SUB_FILES+=	pkg-message

INSTALL_TARGET=	install-strip

USE_RC_SUBR=	gmond

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGMETAD}
USE_RC_SUBR+=	gmetad

LIB_DEPENDS+=	librrd.so:databases/rrdtool
CONFIGURE_ARGS+=	--with-gmetad
PLIST_SUB+=	GMETAD=""
SUB_LIST+=	GMETAD=""
.else
PLIST_SUB+=	GMETAD="@comment "
SUB_LIST+=	GMETAD="\#"
.endif

USE_LDCONFIG=	yes

CONF_DIR=	${PREFIX}/etc

MODULES=	modcpu.so \
		moddisk.so \
		modload.so \
		modmem.so \
		modmulticpu.so \
		modnet.so \
		modproc.so \
		modpython.so \
		modsys.so

# gmond.conf.5 and gmond.conf.html can be generated from conf.pod, but
# doing so requires perl installed in the build stage.
post-patch:
	${REINPLACE_CMD} \
		-e "s|/etc/ganglia/\(gm[a-z]*d.conf\)|${PREFIX}/etc/\1|g" \
		${WRKSRC}/README \
		${WRKSRC}/mans/gmetad.1 \
		${WRKSRC}/mans/gmond.1
	${REINPLACE_CMD} -e "s|nobody|ganglia|g" \
		${WRKSRC}/gmetad/gmetad.conf.in \
		${WRKSRC}/gmond/conf.pod \
		${WRKSRC}/gmond/gmond.conf.5 \
		${WRKSRC}/gmond/gmond.conf.html

post-build:
	${WRKSRC}/gmond/gmond -t > ${WRKDIR}/gmond.conf

post-install:
	${INSTALL_DATA} ${WRKDIR}/gmond.conf \
		${STAGEDIR}${PREFIX}/etc/gmond.conf.sample
.if ${PORT_OPTIONS:MGMETAD}
	${INSTALL_SCRIPT} ${FILESDIR}/gmetasnap.sh \
		${STAGEDIR}${PREFIX}/sbin/gmetasnap
	${INSTALL_DATA} ${WRKSRC}/gmetad/gmetad.conf \
		${STAGEDIR}${PREFIX}/etc/gmetad.conf.sample
	${INSTALL_MAN} ${WRKSRC}/mans/gmetad.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
.endif
	${INSTALL_MAN} \
		${WRKSRC}/mans/gmetric.1 \
		${WRKSRC}/mans/gmond.1 \
		${WRKSRC}/mans/gstat.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/gmond/gmond.conf.5 \
		${STAGEDIR}${MANPREFIX}/man/man5
	${MKDIR} ${STAGEDIR}/var/db/ganglia/rrds
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ganglia/python_modules

.include <bsd.port.mk>
