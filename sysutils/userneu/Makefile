# Created by: Andreas Fehlner (fehlner@gmx.de)
# $FreeBSD$

PORTNAME=	userneu
PORTVERSION=	1.38
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://btw23.de/johannes/userneu/ \
		http://home.arcor.de/fehlner/fbsd_ports/ \
		http://home.arcor.de/teambushido/fbsd_ports/
DISTNAME=	${PORTNAME}-${PORTVERSION}_1

MAINTAINER=	fehlner@gmx.de
COMMENT=	Account management and creation tool

RUN_DEPENDS=	\
    p5-Crypt-PasswdMD5>=0:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
    p5-Crypt-RandPasswd>=0:${PORTSDIR}/security/p5-Crypt-RandPasswd

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

CONFLICTS=	userneu-devel-[0-9]*

SCRIPTS=	userneu.pl userquick.pl smbrepair.pl
MAN8=		userneu.8 userquick.8
DOCS=		BUGS CHANGES CREDITS REQUIREMENTS TODO \
		doc/README doc/INSTALL doc/userneu.pod doc/userquick.pod
EXAMPLES=	list-sample

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN8} ${MANPREFIX}/man/man8
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/sbin
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
