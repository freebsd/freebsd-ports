# New ports collection makefile for:	f-protd
# Date created:			8 March 2007
# Whom:				Scot W. Hetzel <swhetzel@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	f-protd
PORTVERSION=	4.6.7
CATEGORIES=	security
MASTER_SITES=	http://files.f-prot.com/files/bsd-x86/trial/
DISTNAME=	fp-freebsd-ms.trial
IGNOREFILES=	${DISTFILES}

MAINTAINER=	swhetzel@gmail.com
COMMENT=	F-Prot Antivirus for BSD Mail Server

RUN_DEPENDS=	${LOCALBASE}/f-prot/f-prot:${PORTSDIR}/security/f-prot \
		${SITE_PERL}/Anomy/Sanitizer/FProt.pm:${PORTSDIR}/mail/anomy-sanitizer

RESTRICTED=	Restrictive 60 day evaluation license
BROKEN=		does not build

WRKSRC=		${WRKDIR}/f-prot
NO_BUILD=	yes
USE_PERL5=	yes
USE_RC_SUBR=	fprotd.sh fprotd_scanmail.sh

MAN8=		f-prot-milter.8 f-prot-qmail.8 f-protd.8 scan-mail.pl.8

ONLY_FOR_ARCHS=	i386 amd64

do-install:
	${MKDIR} ${PREFIX}/f-prot/backups
	${CP} ${WRKSRC}/LICENSE-FPAV ${PREFIX}/f-prot/LICENSE-FPAV.f-protd
	${INSTALL_PROGRAM} ${WRKSRC}/f-protd ${PREFIX}/f-prot/
	${INSTALL_PROGRAM} ${WRKSRC}/tools/f-prot-milter ${PREFIX}/f-prot/tools/
	${INSTALL_PROGRAM} ${WRKSRC}/tools/f-prot-qmail ${PREFIX}/f-prot/tools/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/scan-mail.pl ${PREFIX}/f-prot/tools/
.for manpage in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man_pages/${manpage} ${MANPREFIX}/man/man8/
.endfor

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -Rp ${WRKSRC}/doc_ms/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
