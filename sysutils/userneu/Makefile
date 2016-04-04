# Created by: Andreas Fehlner (fehlner@gmx.de)
# $FreeBSD$

PORTNAME=	userneu
PORTVERSION=	1.38
DISTVERSIONSUFFIX=	_1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://btw23.de/johannes/userneu/ \
		http://home.arcor.de/fehlner/fbsd_ports/ \
		http://home.arcor.de/teambushido/fbsd_ports/

MAINTAINER=	fehlner@gmx.de
COMMENT=	Account management and creation tool

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Crypt-PasswdMD5>=0:security/p5-Crypt-PasswdMD5 \
		p5-Crypt-RandPasswd>=0:security/p5-Crypt-RandPasswd

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	userquick.pl smbrepair.pl userneu.pl

CONFLICTS=	userneu-devel-[0-9]*

SCRIPTS=	userneu.pl userquick.pl smbrepair.pl
DOCS=		BUGS CHANGES CREDITS REQUIREMENTS TODO \
		doc/README doc/INSTALL doc/userneu.pod doc/userquick.pod
EXAMPLES=	list-sample
OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} userneu.8 userquick.8 ${STAGEDIR}${MANPREFIX}/man/man8
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
