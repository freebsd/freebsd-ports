# New ports collection makefile for:	userneu
# Date created:		7 August 2003
# Whom:			Andreas Fehlner (fehlner@gmx.de)
#
# $FreeBSD$
#

PORTNAME=	userneu
PORTVERSION=	1.38
CATEGORIES=	sysutils
MASTER_SITES=	http://btmdx8.mat.uni-bayreuth.de/~johannes/files/userneu/ \
		http://home.arcor.de/fehlner/inhalt/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}_1

MAINTAINER=	fehlner@gmx.de
COMMENT=	Account management and creation tool

RUN_DEPENDS=	\
    ${SITE_PERL}/Crypt/PasswdMD5.pm:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
    ${SITE_PERL}/Crypt/RandPasswd.pm:${PORTSDIR}/security/p5-Crypt-RandPasswd \
    ${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

USE_PERL5_RUN=	yes
NO_BUILD=	yes

CONFLICTS=	userneu-devel-*

SCRIPTS=	userneu.pl userquick.pl smbrepair.pl
MAN8=		userneu.8 userquick.8
DOCS=		BUGS CHANGES CREDITS REQUIREMENTS TODO \
		doc/README doc/INSTALL doc/userneu.pod doc/userquick.pod
EXAMPLES=	list-sample

do-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN8} ${MANPREFIX}/man/man8
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/sbin
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
