# Created by: mcglk@artlogix.com
# $FreeBSD$

PORTNAME=	scponly
PORTVERSION=	4.8.20110526
PORTREVISION=	1
CATEGORIES=	shells security
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-snapshots
DISTNAME=	${PORTNAME}-20110526
EXTRACT_SUFX=	.tgz

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	A tiny shell that only permits scp and sftp

MAN8=		scponly.8

PORTDOCS=	BUILDING-JAILS.TXT INSTALL README SECURITY

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	WILDCARDS GFTP CHROOT RSYNC SCP SVN SVNSERVE UNISON WINSCP \
		DEFAULT_CHDIR DOCS
OPTIONS_DEFAULT=	WILDCARDS
DEFAULT_CHDIR_DESC=	Chdir(2) by default
WILDCARDS_DESC=		Wildcards processing
GFTP_DESC=	gftp support
RSYNC_DESC=	rsync support
CHROOT_DESC=	chroot(8) functionality
SCP_DESC=	vanilla scp support
SVNSERVE_DESC=	Suversion support for svn+ssh://
UNISON_DESC=	Unisson support
WINSCP_DESC=	WinSCP support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if(!exists(/usr/bin/sftp))
RUN_DEPENDS+=	sftp:${PORTSDIR}/security/openssh-portable
BUILD_DEPENDS+=	sftp:${PORTSDIR}/security/openssh-portable
.endif

.if ${PORT_OPTIONS:MDEFAULT_CHDIR}
CONFIGURE_ARGS+=--with-default-chdir=${SCPONLY_DEFAULT_CHDIR}
.endif

.if ${PORT_OPTIONS:MWILDCARDS}
CONFIGURE_ARGS+=--enable-wildcards
.else
CONFIGURE_ARGS+=--disable-wildcards
.endif

.if ${PORT_OPTIONS:MGFTP}
CONFIGURE_ARGS+=--enable-gftp-compat
.else
CONFIGURE_ARGS+=--disable-gftp-compat
.endif

.if ${PORT_OPTIONS:MCHROOT}
PLIST_SUB+=	SCPONLY_CHROOT=""
CONFIGURE_ARGS+=--enable-chrooted-binary
USE_RC_SUBR+=	scponlyc
.else
PLIST_SUB+=	SCPONLY_CHROOT="@comment "
.endif

.if ${PORT_OPTIONS:MRSYNC}
BUILD_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
CONFIGURE_ARGS+=--enable-rsync-compat
.else
CONFIGURE_ARGS+=--disable-rsync-compat
.endif

.if ${PORT_OPTIONS:MSCP}
CONFIGURE_ARGS+=--enable-scp-compat
.else
CONFIGURE_ARGS+=--disable-scp-compat
.endif

.if ${PORT_OPTIONS:MSVN}
CONFIGURE_ARGS+=--enable-svn-compat
.else
CONFIGURE_ARGS+=--disable-svn-compat
.endif

.if ${PORT_OPTIONS:MSVNSERVE}
CONFIGURE_ARGS+=--enable-svnserv-compat
.else
CONFIGURE_ARGS+=--disable-svnserv-compat
.endif

.if ${PORT_OPTIONS:MUNISON}
BUILD_DEPENDS+=	unison:${PORTSDIR}/net/unison
CONFIGURE_ARGS+=--enable-unison-compat
.else
CONFIGURE_ARGS+=--disable-unison-compat
.endif

.if ${PORT_OPTIONS:MWINSCP}
CONFIGURE_ARGS+=--enable-winscp-compat
.else
CONFIGURE_ARGS+=--disable-winscp-compat
.endif

# svn, svnlook ... are per default in subversion
# only check for one of them!
.if ${PORT_OPTIONS:MSVN} || ${PORT_OPTIONS:MSVNSERVE}
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
.endif

RUN_DEPENDS:=	${BUILD_DEPENDS}

post-patch:
	@${ECHO_MSG} "In addition to knobs available from the OPTIONS dialog,"
	@${ECHO_MSG} "you may set SCPONLY_DEFAULT_CHDIR to make users 'cd' to"
	@${ECHO_MSG} "this directory after authentication."

post-install:
	@${ECHO_MSG} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/scponly /etc/shells.bak; \
	  ${ECHO_CMD} ${PREFIX}/bin/scponly) > /etc/shells
	@${RM} /etc/shells.bak
.if ${PORT_OPTIONS:MCHROOT}
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/sbin/scponlyc /etc/shells.bak; \
	  ${ECHO_CMD} ${PREFIX}/sbin/scponlyc) > /etc/shells
	@${RM} /etc/shells.bak
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/setup_chroot.sh ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/config.h ${EXAMPLESDIR}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To setup chroot cage, run the following commands:"
	@${ECHO_MSG} "  1) cd ${EXAMPLESDIR}/ && ${SH} setup_chroot.sh"
	@${ECHO_MSG} "  2) Set scponlyc_enable=\"YES\" in /etc/rc.conf"
	@${ECHO_MSG} "  3) Run ${PREFIX}/etc/rc.d/scponly start"
	@${ECHO_MSG} ""
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For information on several potential security concerns,"
	@${ECHO_MSG} "please read:"
	@${ECHO_MSG} "${DOCSDIR}/SECURITY"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
