PORTNAME=	monitor-core
PORTVERSION=	3.7.2
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	SF/ganglia/ganglia%20monitoring%20core/${PORTVERSION}
PKGNAMEPREFIX=	ganglia-
.if defined(CLUSTER)
PKGNAMESUFFIX=	-${CLUSTER}
.endif
DISTNAME=	ganglia-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ganglia cluster monitor, monitoring daemon
WWW=		http://ganglia.info/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libconfuse.so:devel/libconfuse \
		libpcre.so:devel/pcre \
		libexpat.so:textproc/expat2

USES=		libtool localbase:ldflags pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	gmond

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-setuid=ganglia --enable-setgid=ganglia \
		--disable-python
CONFIGURE_ENV=	GANGLIA_ACK_SYSCONFDIR=1

INSTALL_TARGET=	install-strip

SUB_FILES+=	pkg-message

USERS=		ganglia
GROUPS=		ganglia

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	GMETAD
OPTIONS_DEFAULT=	GMETAD
OPTIONS_SUB=	yes

GMETAD_DESC=	include gmetad

GMETAD_LIB_DEPENDS=	librrd.so:databases/rrdtool
GMETAD_CONFIGURE_ON=	--with-gmetad
GMETAD_SUB_LIST=	GMETAD=""
GMETAD_SUB_LIST_OFF=	GMETAD="\#"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.if ${PORT_OPTIONS:MGMETAD}
USE_RC_SUBR+=	gmetad
.endif

CONF_DIR=	${PREFIX}/etc

MODULES=	modcpu.so \
		moddisk.so \
		modload.so \
		modmem.so \
		modmulticpu.so \
		modnet.so \
		modproc.so \
		modsys.so

# gmond.conf.5 and gmond.conf.html can be generated from conf.pod, but
# doing so requires perl installed in the build stage.
pre-configure:
	@${REINPLACE_CMD} \
		-e "s|/etc/ganglia/\(gm[a-z]*d.conf\)|${PREFIX}/etc/\1|g" \
		${WRKSRC}/README \
		${WRKSRC}/mans/gmetad.1 \
		${WRKSRC}/mans/gmond.1
	@${REINPLACE_CMD} -e "s|nobody|ganglia|g" \
		${WRKSRC}/gmetad/gmetad.conf.in \
		${WRKSRC}/gmond/conf.pod \
		${WRKSRC}/gmond/gmond.conf.5 \
		${WRKSRC}/gmond/gmond.conf.html

post-build:
	@${WRKSRC}/gmond/gmond -t > ${WRKDIR}/gmond.conf

post-install:
	${INSTALL_DATA} ${WRKDIR}/gmond.conf \
		${STAGEDIR}${PREFIX}/etc/gmond.conf.sample
	${MKDIR} ${STAGEDIR}/var/db/ganglia/rrds
	@${CHMOD} -R a+rX ${STAGEDIR}/var/db/ganglia

post-install-GMETAD-on:
	${INSTALL_SCRIPT} ${FILESDIR}/gmetasnap.sh \
		${STAGEDIR}${PREFIX}/sbin/gmetasnap
	${INSTALL_DATA} ${WRKSRC}/gmetad/gmetad.conf \
		${STAGEDIR}${PREFIX}/etc/gmetad.conf.sample

.include <bsd.port.mk>
