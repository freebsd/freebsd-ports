# New ports collection makefile for:	fspd
# Date created:				2001-04-10
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fspd
PORTVERSION=	2.8.1.26
CATEGORIES=	net
MASTER_SITES=	SF/fsp/fsp/2.8.1b26
DISTNAME=	fsp-2.8.1b26

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	FSP daemon, clients, and scanner

BUILD_DEPENDS=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat

CLIENTS=	fcatcmd fcdcmd fducmd ffindcmd fgetcmd fgrabcmd fhostcmd \
		flscmd fmkdir fprocmd fput frmcmd frmdircmd fver fspmerge \
		fstatcmd fmvcmd fbye fsetupcmd
DOCDIR=		share/doc/${PORTNAME}
PORTDOCS=	BETA.README COPYRIGHT ChangeLog FILES INFO INSTALL MACHINES \
		TODO PROTOCOL HISTORY faq.html fsp-faq.html
MAN1=		fcatcmd.1 fcdcmd.1 fducmd.1 ffindcmd.1 fgetcmd.1 fgrabcmd.1 \
		fhostcmd.1 flscmd.1 fmkdir.1 fprocmd.1 fput.1 \
		frmcmd.1 frmdircmd.1 fspd.1 fspscan.1 fver.1 \
		fstatcmd.1 fmvcmd.1 fsetupcmd.1
MAN5=		fsp_prof.5 fspsites.5
MAN7=		fsp_env.7
MLINKS=		fcatcmd.1 fcat.1 fcdcmd.1 fcd.1 fducmd.1 fdu.1 \
		ffindcmd.1 ffind.1 fgetcmd.1 fget.1 fgrabcmd.1 fgrab.1 \
		fhostcmd.1 fhost.1 flscmd.1 fls.1 fprocmd.1 fpro.1 \
		frmdircmd.1 frmdir.1 fstatcmd.1 fstat.1 fmvcmd.1 fmv.1 \
		fsetupcmd.1 fsetup.1

USE_SCONS=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS=	NOCLIENTS "Omit client commands" off \
		INFINITE  "Infinite retry in client commands" off

.include <bsd.port.pre.mk>

.if defined(WITH_INFINITE)
SCONS_ARGS+=	disable-timeout=yes
.endif

.if !defined(WITH_NOCLIENTS)
.for command in ${CLIENTS}
PLIST_FILES+=	bin/${command}
.endfor
.else
SCONS_ARGS+=	without-clients=yes
.endif

PLIST_FILES+=	etc/fspd.conf.sample bin/fspscan bin/fspd

post-extract:
	@${CP} ${WRKSRC}/doc/PROTOCOL ${WRKSRC}
	@${CP} ${WRKSRC}/doc/HISTORY ${WRKSRC}

post-build:
	@${CP} ${WRKSRC}/doc/*.html ${WRKSRC}

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
.if !defined(WITH_NOCLIENTS)
.for command in ${CLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${command} ${PREFIX}/bin
.endfor
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/fspscan ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/server/fspd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fspd.conf ${PREFIX}/etc/fspd.conf.sample
.for page in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${page} ${PREFIX}/man/man1
.endfor
.for page in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/man/${page} ${PREFIX}/man/man5
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/${MAN7} ${PREFIX}/man/man7

.include <bsd.port.post.mk>
