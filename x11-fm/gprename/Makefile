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

OPTIONS_DEFINE=	DOCS

RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext

WRKSRC=		${WRKDIR}/${PORTNAME}/trunk

USE_PERL5=	run
USES=		gettext perl5 tar:bzip2 shebangfix
SHEBANG_FILES=	bin/gprename
NO_BUILD=	yes

post-extract:
	@${RM} -rf ${WRKSRC}/build

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}| ; \
		 s|(DESTDIR)|(DESTDIR)${PREFIX}| ; \
		 s|$$(CURDIR)|$$(.CURDIR)| ; \
		 s|uninstall build|build| ; \
		 s|share/man|man|' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
