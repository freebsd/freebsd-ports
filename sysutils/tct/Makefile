# New ports collection makefile for:	tct
# Date created:		21 September 2003
# Whom:			Francisco Gomez <francisco@gomezmarin.com>
#
# $FreeBSD$
#

PORTNAME=	tct
PORTVERSION=	1.14
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fish.com/tct/ \
		http://www.porcupine.org/forensics/

MAINTAINER=	francisco@gomezmarin.com
COMMENT=	Analyzer for forensic data

USE_PERL5=	yes
PKGMESSAGE=	${WRKSRC}/pkg-message

MAN1=		file-tct.1 ils.1 mactime.1 md5-tct.1 pcat.1 grave-robber.1 lastcomm.1 major_minor.1 timeout.1 icat.1 lazarus.1 unrm.1
MAN5=		magic.5 tm-format.5

MYPORTDOCS=	CHANGES COPYRIGHT INSTALL LICENSE MANIFEST OS-NOTES README.FIRST TODO docs/README docs/design-notes docs/lazarus.README docs/grave-robber.README docs/mac.README

.include <bsd.port.pre.mk>

post-patch:
	${SED} -e 's,/usr/local,${PREFIX},g' pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DOCSDIR}/lib
	@${MKDIR} ${DOCSDIR}/lazarus
	@${MKDIR} ${DOCSDIR}/etc
	@${MKDIR} ${DOCSDIR}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/file ${PREFIX}/bin/file-tct
	${INSTALL_DATA} -m 555 ${WRKSRC}/bin/grave-robber ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/icat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ils ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lastcomm ${PREFIX}/bin
	${INSTALL_DATA} -m 555 ${WRKSRC}/bin/mactime ${PREFIX}/bin
	${INSTALL_DATA} -m 555 ${WRKSRC}/lazarus/lazarus ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/lazarus ${DOCSDIR}/lazarus/lazarus
	${LN} -s ${PREFIX}/bin/file-tct ${DOCSDIR}/bin/file
	${INSTALL_PROGRAM} ${WRKSRC}/bin/major_minor ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/md5 ${PREFIX}/bin/md5-tct
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pcat ${PREFIX}/bin
	${INSTALL_DATA} -m 555 ${WRKSRC}/bin/strip_tct_home ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/unrm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/timeout ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/file.1 ${PREFIX}/man/man1/file-tct.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/md5.1 ${PREFIX}/man/man1/md5-tct.1
	@${MKDIR} ${DOCSDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DOCSDIR}/lib
	@${MKDIR} ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/savecore.pl ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/paths.pl ${PREFIX}/${SITE_PERL_REL}

post-install:
.if !defined(NOPORTDOCS)
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.for f in ${MAN1:S/file-tct.1//:S/md5-tct.1//}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f} ${PREFIX}/man/man1
.endfor
.for f in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/man/man5/${f} ${PREFIX}/man/man5
.endfor
	@${MKDIR} ${DOCSDIR}/conf
	${INSTALL_DATA} ${WRKSRC}/conf/* ${DOCSDIR}/conf
	${INSTALL_DATA} ${WRKSRC}/etc/magic ${DOCSDIR}/etc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
