# New ports collection makefile for:	tct
# Date created:		21 September 2003
# Whom:			Francisco Gomez <francisco@gomezmarin.com>
#
# $FreeBSD$
#

PORTNAME=	tct
PORTVERSION=	1.15
CATEGORIES=	sysutils
MASTER_SITES=	http://www.porcupine.org/forensics/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyzer for forensic data

USE_PERL5=	yes
MAKE_ENV=	OPT="${CFLAGS}"

MAN1=		file-tct.1 grave-robber.1 icat.1 ils.1 lastcomm.1 lazarus.1 \
		mactime.1 major_minor.1 md5-tct.1 pcat.1 timeout.1 unrm.1
MAN5=		magic.5 tm-format.5

.include <bsd.port.pre.mk>

.if defined(WITH_LSOF)
RUN_DEPENDS+=	${LOCALBASE}/sbin/lsof:${PORTSDIR}/sysutils/lsof
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC|#CC|g ; \
		 s|^DEBUG|#DEBUG|g ; \
		 s|^OPT|#OPT|g'
	@${REINPLACE_CMD} -e '/TCT_HOME/s|$$cwd|${DATADIR}|g' ${WRKSRC}/reconfig
	@${REINPLACE_CMD} -e 's|/usr/local/bin|${LOCALBASE}/bin|g ; \
		 s|/usr/X11R6/bin|${X11BASE}/bin|g' ${WRKSRC}/conf/paths.pl
	@${RM} ${WRKSRC}/conf/paths.pl.bak

do-install:
.for f in icat ils lastcomm major_minor pcat unrm timeout
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin/${f}
.endfor
.for f in file grave-robber mactime strip_tct_home
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin/${f}
.endfor
.for f in file md5
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin/${f}-tct
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/lazarus/lazarus ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/bin
	${LN} -s ${PREFIX}/bin/file-tct ${DATADIR}/bin/file
	@${MKDIR} ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/savecore.pl ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/paths.pl ${PREFIX}/${SITE_PERL_REL}
	@${MKDIR} ${DATADIR}/conf
	${INSTALL_DATA} ${WRKSRC}/conf/* ${DATADIR}/conf
	@${MKDIR} ${DATADIR}/etc
	${INSTALL_DATA} ${WRKSRC}/etc/magic ${DATADIR}/etc
	@${MKDIR} ${DATADIR}/lazarus
	${LN} -s ${PREFIX}/bin/lazarus ${DATADIR}/lazarus/lazarus
	@${MKDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DATADIR}/lib
	${INSTALL_MAN} ${WRKSRC}/man/man1/file.1 ${MANPREFIX}/man/man1/file-tct.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/md5.1 ${MANPREFIX}/man/man1/md5-tct.1
.for f in ${MAN1:S/file-tct.1//:S/md5-tct.1//}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f} ${MANPREFIX}/man/man1
.endfor
.for f in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/man/man5/${f} ${MAN5PREFIX}/man/man5
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in CHANGES COPYRIGHT INSTALL LICENSE MANIFEST OS-NOTES README.FIRST TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.for f in README design-notes grave-robber.README lazarus.README mac.README
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
