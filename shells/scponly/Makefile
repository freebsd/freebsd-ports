# New ports collection makefile for:	scponly
# Date created:				2002/07/23
# Whom:					mcglk@artlogix.com
#
# $FreeBSD$
#

PORTNAME=	scponly
PORTVERSION=	4.8
PORTREVISION=	3
CATEGORIES=	shells security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	A tiny shell that only permits scp and sftp

MAN8=		scponly.8

PORTDOCS=	BUILDING-JAILS.TXT INSTALL README SECURITY

GNU_CONFIGURE=	yes

OPTIONS=	SCPONLY_WILDCARDS "wildcards processing" on \
		SCPONLY_GFTP "gftp compatibility" on \
		SCPONLY_CHROOT "chroot functionality" off \
		SCPONLY_RSYNC "rsync compatibility" off \
		SCPONLY_SCP "vanilla scp compatibility" off \
		SCPONLY_SFTP_LOGGING "sftp logging compatibility" off \
		SCPONLY_SVN "subversion compatibility" off \
		SCPONLY_SVNSERVE "subversion compatibility svn+ssh://" off \
		SCPONLY_UNISON "unison compatibility" off \
		SCPONLY_WINSCP "WinSCP compatibility" off

.include <bsd.port.pre.mk>

.if defined(SCPONLY_DEFAULT_CHDIR) && !empty(SCPONLY_DEFAULT_CHDIR)
CONFIGURE_ARGS+=--with-default-chdir=${SCPONLY_DEFAULT_CHDIR}
.endif

.if defined(WITHOUT_SCPONLY_WILDCARDS)
CONFIGURE_ARGS+=--disable-wildcards
.endif

.if defined(WITHOUT_SCPONLY_GFTP)
CONFIGURE_ARGS+=--disable-gftp-compat
.endif

.if defined(WITH_SCPONLY_CHROOT)
PLIST_SUB+=	SCPONLY_CHROOT=""
CONFIGURE_ARGS+=--enable-chrooted-binary
USE_RC_SUBR+=	scponlyc
.else
PLIST_SUB+=	SCPONLY_CHROOT="@comment "
.endif

.if defined(WITH_SCPONLY_RSYNC)
BUILD_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS+=	${BUILD_DEPENDS}
CONFIGURE_ARGS+=--enable-rsync-compat
.endif

.if defined(WITH_SCPONLY_SCP)
CONFIGURE_ARGS+=--enable-scp-compat
.endif

.if defined(WITH_SCPONLY_SFTP_LOGGING)
CONFIGURE_ARGS+=--enable-sftp-logging-compat
.endif

.if defined(WITH_SCPONLY_SVN)
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
RUN_DEPENDS+=	${BUILD_DEPENDS}
CONFIGURE_ARGS+=--enable-svn-compat
.endif

.if defined(WITH_SCPONLY_SVNSERVE)
BUILD_DEPENDS+=	svnserve:${PORTSDIR}/devel/subversion
RUN_DEPENDS+=	${BUILD_DEPENDS}
CONFIGURE_ARGS+=--enable-svnserv-compat
.endif

.if defined(WITH_SCPONLY_UNISON)
BUILD_DEPENDS+=	unison:${PORTSDIR}/net/unison
RUN_DEPENDS+=	${BUILD_DEPENDS}
CONFIGURE_ARGS+=--enable-unison-compat
.endif

.if defined(WITH_SCPONLY_WINSCP)
CONFIGURE_ARGS+=--enable-winscp-compat
.endif

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
.if defined(WITH_SCPONLY_CHROOT)
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
.if !defined(NOPORTDOCS)
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

.include <bsd.port.post.mk>
