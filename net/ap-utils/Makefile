# New ports collection makefile for:    ap-utils
# Date created:		2002/07/10
# Whom:			Jerry A! <jerry@thehutt.org>
#
# $FreeBSD$
#

PORTNAME=	ap-utils
PORTVERSION=	1.3.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	daniel+aputils@pelleg.org
COMMENT=	A set of utilities to configure and monitor wireless access points

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	LDFLAGS="-lintl -L${LOCALBASE}/lib"
MAN8=		ap-trapd.8 ap-mrtg.8 ap-config.8

post-patch:
	@${REINPLACE_CMD} -e 's|_nl_domain_bindings|libintl_nl_domain_bindings|' ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/Documentation && \
		${INSTALL_DATA} FAQ Ovislink-HOWTO.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
