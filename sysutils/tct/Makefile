# New ports collection makefile for:	tct
# Date created:		21 September 2003
# Whom:			Francisco Gomez <francisco@gomezmarin.com>
#
# $FreeBSD$
#

PORTNAME=	tct
PORTVERSION=	1.12
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fish.com/tct/ \
		http://www.porcupine.org/forensics/

MAINTAINER=	francisco@gomezmarin.com
COMMENT=	Analyzer for forensic data

RUN_DEPENDS+=	${LOCALBASE}/sbin/lsof:${PORTSDIR}/sysutils/lsof

CONFLICTS=	file-*

USE_PERL5_RUN=	yes

MAN1=		ils.1 mactime.1 pcat.1 grave-robber.1 lastcomm.1 major_minor.1 timeout.1 icat.1 lazarus.1 unrm.1
MAN5=		magic.5 tm-format.5

MYPORTDOCS=	CHANGES COPYRIGHT INSTALL LICENSE MANIFEST OS-NOTES README.FIRST TODO docs/README docs/design-notes docs/lazarus.README docs/grave-robber.README docs/mac.README

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Install broken"
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/file ${LOCALBASE}/bin/file-tct
	@${INSTALL_DATA} -m 555 ${WRKSRC}/bin/grave-robber ${LOCALBASE}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/icat ${LOCALBASE}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/ils ${LOCALBASE}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/lastcomm ${LOCALBASE}/bin
	@${INSTALL_DATA} -m 555 ${WRKSRC}/bin/mactime ${LOCALBASE}/bin
	@${INSTALL_DATA} -m 555 ${WRKSRC}/lazarus/lazarus ${LOCALBASE}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/major_minor ${LOCALBASE}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/md5 ${LOCALBASE}/bin/md5-tct
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/pcat ${LOCALBASE}/bin
	@${INSTALL_DATA} -m 555 ${WRKSRC}/bin/strip_tct_home ${LOCALBASE}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/unrm ${LOCALBASE}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/timeout ${LOCALBASE}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/man1/file.1 ${PREFIX}/man/man1/file-tct.1
	@${INSTALL_MAN} ${WRKSRC}/man/man1/md5.1 ${PREFIX}/man/man1/md5-tct.1
	@${CP} ${WRKSRC}/lib/* ${SITE_PERL}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tct
.for file in ${MYPORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tct
.endfor
.endif

.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${file} ${PREFIX}/man/man1
.endfor

.for file in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/man/man5/${file} ${PREFIX}/man/man5
.endfor

	@${MKDIR} ${PREFIX}/share/doc/tct/conf
	@${CP} ${WRKSRC}/conf/* ${PREFIX}/share/doc/tct/conf
	@${CP} ${WRKSRC}/conf/paths.pl ${SITE_PERL}

.include <bsd.port.post.mk>
