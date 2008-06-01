# New ports collection makefile for:    ap-utils
# Date created:		2002/07/10
# Whom:			Jerry A! <jerry@thehutt.org>
#
# $FreeBSD$
#

PORTNAME=	ap-utils
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of utilities to configure and monitor wireless access points

DEPRECATED=		Does not work with gcc4.2; appears to be abandoned
EXPIRATION_DATE=	2008-04-07

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_BZIP2=	yes
CONFIGURE_ENV=	LDFLAGS="-lintl -L${LOCALBASE}/lib"
MAN8=		ap-trapd.8 ap-mrtg.8 ap-config.8

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
BROKEN=		Does not build without gettext
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Broken with gcc 4.2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|_nl_domain_bindings|libintl_nl_domain_bindings|' ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/Documentation && \
		${INSTALL_DATA} FAQ Ovislink-HOWTO.html HARDWARE-NOTES README.ap-gl ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
