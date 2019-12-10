# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jailkit
PORTVERSION=	2.21
CATEGORIES=	shells
MASTER_SITES=	http://olivier.sessink.nl/jailkit/ \
		http://www.sfr-fresh.com/unix/privat/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Utilities to limit user accounts to specific files and/or commands

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		python

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHONINTERPRETER=${PYTHON_CMD}
PORTDOCS=	COPYRIGHT README.txt

OPTIONS_DEFINE=	DOCS PROCMAIL
OPTIONS_SUB=	yes

PROCMAIL_DESC=	Build procmail(1) wrapper

PROCMAIL_CONFIGURE_ENV_OFF=	ac_cv_path_PROCMAILPATH=no
PROCMAIL_BUILD_DEPENDS=	procmail:mail/procmail
PROCMAIL_RUN_DEPENDS=	procmail:mail/procmail

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jk_uchroot \
		${STAGEDIR}${PREFIX}/sbin/jk_socketd \
		${STAGEDIR}${PREFIX}/sbin/jk_chrootlaunch \
		${STAGEDIR}${PREFIX}/sbin/jk_chrootsh \
		${STAGEDIR}${PREFIX}/sbin/jk_lsh

post-install-PROCMAIL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/jk_procmailwrapper

.include <bsd.port.mk>
