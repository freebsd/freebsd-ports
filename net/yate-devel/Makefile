# New ports collection makefile for:	yate
# Date created:		2006-12-11
# Whom:			Balwinder S "bsd" Dheeman <bdheeman@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	yate
PORTVERSION=	1.3.0.p2
DISTVERSION=	${PORTVERSION:S/.p/-/}
PORTREVISION=	3
CATEGORIES=	net comms
MASTER_SITES=	http://cto.homelinux.net/pub/FreeBSD/ports/distfiles/ \
		${MASTER_SITE_LOCAL}
PKGNAMESUFFIX=	-devel

MAINTAINER=	bdheeman@gmail.com
COMMENT=	Yet Another Telephony Engine

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm \
		speex.1:${PORTSDIR}/audio/speex

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_LDCONFIG=	yes
WANT_GNOME=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-fdsize \
		--mandir=${LOCALBASE}/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323
MAN8=		yate-config.8 yate.8

ONLY_FOR_ARCHS=	amd64 i386 sparc64

OPTIONS=	X11 "Build GUI client; yate-gtk2" on \
		MYSQL "MySQL Database support" off \
		PGSQL "PostgreSQL Database support" on \
		H323 "H323 software channel/protocol support" on \
		ZAPTEL "Zaptel hardware channel/driver support" on \
		FAX "Fax software channel/driver support" on

DOCSDIR=	${LOCALBASE}/share/doc/yate
PORTDOCS=	${DOCSDIR}/*
PLIST_SUB=	BRISTUFF="@comment "
PLIST_SUB+=	VERSION=${PORTVERSION:S/.p2//}
SUB_FILES=	pkg-message
USE_RC_SUBR=	yate.sh
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.p2//}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-libgtk2
MAKE_ENV+=	WITH_X11=1
PLIST_SUB+=	WITH_X11=""
USE_GNOME=	gtk20
.else
CONFIGURE_ARGS+=	--without-libgtk2
PLIST_SUB+=	WITH_X11="@comment "
.endif

.if !defined(WITHOUT_MYSQL)
MAKE_ENV+=	WITH_MYSQL=1
PLIST_SUB+=	WITH_MYSQL=""
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--with-mysql=/none
PLIST_SUB+=	WITH_MYSQL="@comment "
.endif

.if !defined(WITHOUT_PGSQL)
CONFIGURE_ARGS+=	--with-libpq=${LOCALBASE}
MAKE_ENV+=	WITH_PGSQL=1
PLIST_SUB+=	WITH_PGSQL=""
USE_PGSQL=	yes
.else
PLIST_SUB+=	WITH_PGSQL="@comment "
.endif

.if ${ARCH} != "i386"
WITHOUT_H323=	1
WITHOUT_ZAPTEL=	1
.endif

.if !defined(WITHOUT_H323)
CONFIGURE_ARGS+=	--with-pwlib=${LOCALBASE} \
			--with-openh323=${LOCALBASE}
LIB_DEPENDS+=	pt_r.1:${PORTSDIR}/devel/pwlib \
		h323_r.1:${PORTSDIR}/net/openh323
MAKE_ENV+=	WITH_H323=1
PLIST_SUB+=	WITH_H323=""
.else
PLIST_SUB+=	WITH_H323="@comment "
.endif

.if !defined(WITHOUT_ZAPTEL)
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/zaptel/zaptel.h:${PORTSDIR}/misc/zaptel
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	ztcfg:${PORTSDIR}/misc/zaptel
MAKE_ENV+=	WITH_ZAPTEL=1
PLIST_SUB+=	WITH_ZAPTEL=""
.else
MAKE_ENV+=	WITHOUT_ZAPTEL=1
PLIST_SUB+=	WITH_ZAPTEL="@comment "
.endif

.if !defined(WITHOUT_FAX)
LIB_DEPENDS+=	spandsp.2:${PORTSDIR}/comms/spandsp-devel
MAKE_ENV+=	WITH_FAX=1
PLIST_SUB+=	WITH_FAX=""
.else
PLIST_SUB+=	WITH_FAX="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/modules/Makefile.in

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} files/README.too ${DOCSDIR}
	@cd ${PREFIX}/etc/${PORTNAME}; for cfg in *.sample; do test -f $${cfg%%.sample} || cp -p $${cfg} $${cfg%%.sample}; done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
