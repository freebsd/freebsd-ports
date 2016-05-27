# Created by: Rashid N. Achilov <shelton@granch.ru>
# $FreeBSD$

PORTNAME=	mountsmb2
PORTVERSION=	0.90.2
CATEGORIES=	sysutils net
MASTER_SITES=	LOCAL/lippe

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SMB/CIFS shares mounting scripts to do it at login

RUN_DEPENDS=	nbtscan:net-mgmt/nbtscan \
		sudo:security/sudo

USES=		tar:bzip2
NO_BUILD=	yes

SCRIPTS=	smb2nsmbrc mountsmb2

SUB_FILES=	pkg-message

PLIST_FILES=	bin/mountsmb2 bin/smb2nsmbrc
PORTDOCS=	README.FreeBSD
PORTEXAMPLES=	sudoers .login .nsmbrc .mssmbrc nsmb.conf

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
