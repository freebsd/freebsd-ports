# Created by: trevor
# $FreeBSD$

PORTNAME=	gprename
PORTVERSION=	2.7
PORTEPOCH=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl script for renaming multiple files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext

WRKSRC=		${WRKDIR}/${PORTNAME}/trunk

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
USE_GETTEXT=	yes
NO_BUILD=	yes

MAN1=		gprename.1

post-extract:
	@${RM} -rf ${WRKSRC}/build

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*|${PERL}|' ${WRKSRC}/bin/gprename
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}| ; \
		 s|$$(CURDIR)|$$(.CURDIR)| ; \
		 s|uninstall build|build| ; \
		 s|share/man|man|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
