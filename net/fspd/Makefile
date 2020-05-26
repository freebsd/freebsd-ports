# Created by: trevor
# $FreeBSD$

PORTNAME=	fspd
PORTVERSION=	2.8.1.29
CATEGORIES=	net
MASTER_SITES=	SF/fsp/fsp/2.8.1b29
DISTNAME=	fsp-2.8.1b29

MAINTAINER=	hsn@sendmail.cz
COMMENT=	FSP daemon, clients, and scanner

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		scons:python2 tar:bzip2

CLIENTS=	fcatcmd fcdcmd fducmd ffindcmd fgetcmd fgrabcmd fhostcmd \
		flscmd fmkdir fprocmd fput frmcmd frmdircmd fver fspmerge \
		fstatcmd fmvcmd fbye fsetupcmd
FSPDOCS=	BETA.README COPYRIGHT ChangeLog FILES INFO INSTALL MACHINES \
		TODO PROTOCOL HISTORY faq.html
MAN1CLIENT=	fcatcmd.1 fcdcmd.1 fducmd.1 ffindcmd.1 fgetcmd.1 fgrabcmd.1 \
		fhostcmd.1 flscmd.1 fmkdir.1 fprocmd.1 fput.1 frmcmd.1 \
		frmdircmd.1 fver.1 fstatcmd.1 fmvcmd.1 fsetupcmd.1
MAN1SERVER=	fspscan.1 fspd.1
MAN5CLIENT=	fsp_prof.5 fspsites.5
MAN7CLIENT=	fsp_env.7

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	CLIENTS INFINITE DOCS
CLIENTS_DESC=	Install client commands
INFINITE_DESC=	Infinite retry in client commands

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINFINITE}
SCONS_ARGS+=	disable-timeout=yes
.endif

.if ! ${PORT_OPTIONS:MCLIENTS}
SCONS_ARGS+=	without-clients=yes
.endif

post-extract:
	@${CP} ${WRKSRC}/doc/PROTOCOL ${WRKSRC}
	@${CP} ${WRKSRC}/doc/HISTORY ${WRKSRC}
	: > ${WRKSRC}/doc/SConscript

post-build:
	@${CP} ${WRKSRC}/doc/*.html ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/fspscan ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/server/fspd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fspd.conf \
		${STAGEDIR}${PREFIX}/etc/fspd.conf.sample
.for page in ${MAN1SERVER}
	${INSTALL_MAN} ${WRKSRC}/man/${page} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

do-install-CLIENTS-on:
.for command in ${CLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${command} ${STAGEDIR}${PREFIX}/bin
.endfor
.for page in ${MAN1CLIENT}
	${INSTALL_MAN} ${WRKSRC}/man/${page} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
.for page in ${MAN5CLIENT}
	${INSTALL_MAN} ${WRKSRC}/man/${page} ${STAGEDIR}${MANPREFIX}/man/man5
.endfor
.for page in ${MAN7CLIENT}
	${INSTALL_MAN} ${WRKSRC}/man/${page} ${STAGEDIR}${MANPREFIX}/man/man7
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${FSPDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
