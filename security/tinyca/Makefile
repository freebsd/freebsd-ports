# New ports collection makefile for:	tinyca
# Date created:		17 July 2003
# Whom:			Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	tinyca
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://tinyca.sm-zone.net/

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	Simple graphical interface to manage a small Certification Authority

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gnome.pm:${PORTSDIR}/x11-toolkits/p5-Gnome \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext \
		zip:${PORTSDIR}/archivers/zip \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

WRKSRC=		${WRKDIR}/TinyCA
USE_PERL5=	yes
USE_OPENSSL=	yes
NO_BUILD=	yes
DOC_FILES=	INSTALL
LIB_FILES=	CA.pm CERT.pm GUI.pm KEY.pm OpenSSL.pm REQ.pm TCONFIG.pm

do-install:
	@${MKDIR} ${SITE_PERL}/${PORTNAME}/
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/lib/${file} ${SITE_PERL}/${PORTNAME}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/templates/openssl.cnf ${PREFIX}/etc/tinyca.cnf
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" -e "s:%%SITE_PERL%%:${SITE_PERL}:g" \
		${WRKSRC}/tinyca >${WRKSRC}/tinyca.new
	@${INSTALL_SCRIPT} ${WRKSRC}/tinyca.new ${PREFIX}/bin/tinyca

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
