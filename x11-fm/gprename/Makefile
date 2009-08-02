# New ports collection makefile for:	gprename
# Date created:				2004-03-15
# Whom:					trevor
#
#
# $FreeBSD$
#

PORTNAME=	gprename
PORTVERSION=	2.6.3
PORTEPOCH=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl script for renaming multiple files

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
USE_GETTEXT=	yes
NO_BUILD=	yes
PORTDOCS=	README COPYING
MAN1=		gprename.1
MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} 's|/usr/|${PREFIX}/|' \
		${WRKSRC}/bin/gprename
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|$$(CURDIR)|$$(.CURDIR)|; \
		s|share/man|man|;' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
