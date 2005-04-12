# New ports collection makefile for:	fspd
# Date created:				2001-04-10
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fspd
PORTVERSION=	2.8.1.24
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fsp
DISTNAME=	fsp-2.8.1b24

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	FSP daemon, clients and scanner

CLIENTS=	fcatcmd fcdcmd fducmd ffindcmd fgetcmd fgrabcmd fhostcmd \
		flscmd fmkdir fprocmd fput frmcmd frmdircmd fver fspmerge \
		fstatcmd fmvcmd fbye fsetupcmd
DOCDIR=		share/doc/${PORTNAME}
PORTDOCS=	BETA.README COPYRIGHT ChangeLog FILES INFO INSTALL MACHINES \
		TODO PROTOCOL
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
PLIST_FILES=	bin/fspd bin/fspscan etc/fspd.conf.sample
OPTIONS=	NOCLIENTS "Omit client commands" off \
		INFINITE  "Infinite retry in client commands" off
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_INFINITE)
CONFIGURE_ARGS+=	--disable-timeout
.endif

.if ${OSVERSION} < 500000 || ${ARCH} != "i386"
BROKEN=		"Does not compile on 4.x or on !i386"
.endif

.if !defined(WITH_NOCLIENTS)
.for command in ${CLIENTS}
PLIST_FILES+=	bin/${command}
.endfor
.endif

post-extract:
	${CP} ${WRKSRC}/doc/PROTOCOL ${WRKSRC}

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
