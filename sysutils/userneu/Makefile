# New ports collection makefile for:	userneu
# Date created:		7 August 2003
# Whom:			Andreas Fehlner (fehlner@gmx.de)
#
# $FreeBSD$
#

PORTNAME=	userneu
PORTVERSION=	1.36
CATEGORIES=	sysutils
MASTER_SITES=	http://btmdx8.mat.uni-bayreuth.de/~johannes/files/userneu/ \
		http://home.arcor.de/fehlner/inhalt/download/

MAINTAINER=	fehlner@gmx.de
COMMENT=	Account management and creation tool

RUN_DEPENDS=	\
${SITE_PERL}/Crypt/PasswdMD5.pm:${PORTSDIR}/security/p5-Crypt-PasswdMD5/ \
${SITE_PERL}/Crypt/RandPasswd.pm:${PORTSDIR}/security/p5-Crypt-RandPasswd/ \
${SITE_PERL}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5/

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
GLOCATE=	${PREFIX}/${PORTNAME}
USE_PERL5=	yes
NO_BUILD=	yes

USE_IMAGE=	yes
MANCOMPRESSED=	no
MAN8=	userneu.8 userquick.8

DOCS=	BUGS CHANGES COPYING CREDITS REQUIREMENTS TODO doc/README doc/INSTALL doc/userneu.pod doc/userquick.pod
EXAMPLES=	list-sample

do-install:
	${MKDIR} ${GLOCATE}
	${INSTALL_MAN} 	${WRKSRC}/doc/userneu.8 ${PREFIX}/man/man8
	${INSTALL_MAN}	${WRKSRC}/doc/userquick.8 ${PREFIX}/man/man8
	${INSTALL_SCRIPT} ${WRKSRC}/userneu.pl ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/userquick.pl ${PREFIX}/sbin
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}

.include <bsd.port.mk>
