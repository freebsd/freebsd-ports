# Created by: Andreas Fehlner (fehlner@gmx.de)
# $FreeBSD$

PORTNAME=	userneu
PORTVERSION=	1.43
DISTVERSIONSUFFIX=	b
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://btw23.de/johannes/files/userneu/\
		http://home.arcor.de/fehlner/fbsd_ports/\
		http://home.arcor.de/teambushido/fbsd_ports/
PKGNAMESUFFIX=	-devel

MAINTAINER=	fehlner@gmx.de
COMMENT=	Account management and creation tool

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Crypt-PasswdMD5>=0:security/p5-Crypt-PasswdMD5 \
		p5-Crypt-RandPasswd>=0:security/p5-Crypt-RandPasswd

USES=		perl5 shebangfix
SHEBANG_FILES=	userneu.pl smbrepair.pl
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

CONFLICTS=	userneu-1.*

SCRIPTS=	userneu.pl smbrepair.pl
LDOCS1=		BUGS CHANGES CREDITS REQUIREMENTS TODO
LDOCS2=		README INSTALL userneu.pod userneu.conf.pod
PORTDOCS=	${LDOCS1} ${LDOCS2}
EXAMPLES=	userlist userneu.conf.example
OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} userneu.8 ${STAGEDIR}${MANPREFIX}/man/man8
	cd ${WRKSRC}/doc && ${INSTALL_MAN} userneu.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/sbin
	${LN} -sf userneu.pl ${STAGEDIR}${PREFIX}/sbin/userquick
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${LDOCS1} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${LDOCS2} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
