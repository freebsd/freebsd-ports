PORTNAME=	scponly
PORTVERSION=	4.8.20110526
PORTREVISION=	5
CATEGORIES=	shells security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-snapshots
DISTNAME=	${PORTNAME}-20110526

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Tiny shell that only permits scp and sftp

LICENSE=	BSD2CLAUSE

USES=		cpe tar:tgz

PORTDOCS=	BUILDING-JAILS.TXT INSTALL README SECURITY
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	CHROOT DEFAULT_CHDIR DOCS GFTP RSYNC SCP SUBVERSION SVNSERVE \
		UNISON WILDCARDS WINSCP
OPTIONS_DEFAULT=	WILDCARDS
DEFAULT_CHDIR_DESC=	Chdir(2) by default
WILDCARDS_DESC=		Wildcards processing
GFTP_DESC=	gftp support
RSYNC_DESC=	rsync support
CHROOT_DESC=	chroot(8) functionality
SCP_DESC=	vanilla scp support
SVNSERVE_DESC=	Subversion support for svn+ssh://
UNISON_DESC=	Unisson support
WINSCP_DESC=	WinSCP support

OPTIONS_SUB=	yes

.if !exists(/usr/bin/sftp)
BUILD_DEPENDS+=	openssh-portable>0:security/openssh-portable
RUN_DEPENDS+=	openssh-portable>0:security/openssh-portable
.endif
DEFAULT_CHDIR_CONFIGURE_ON=	--with-default-chdir=${SCPONLY_DEFAULT_CHDIR}
WILDCARDS_CONFIGURE_ENABLE=	wildcards
GFTP_CONFIGURE_ENABLE=		gftp-compat
CHROOT_CONFIGURE_ENABLE=	chrooted-binary
CHROOT_USE=			RC_SUBR=scponlyc
RSYNC_BUILD_DEPENDS=		rsync:net/rsync
RSYNC_RUN_DEPENDS=		rsync:net/rsync
RSYNC_CONFIGURE_ENABLE=		rsync-compat
SCP_CONFIGURE_ENABLE=		scp-compat
SUBVERSION_CONFIGURE_ENABLE=	svn-compat
SUBVERSION_BUILD_DEPENDS=	svn:devel/subversion
SUBVERSION_RUN_DEPENDS=		svn:devel/subversion
SVNSERVE_BUILD_DEPENDS=		svn:devel/subversion
SVNSERVE_RUN_DEPENDS=		svn:devel/subversion
SVNSERVE_CONFIGURE_ENABLE=	svnserv-compat
UNISON_BUILD_DEPENDS=		unison:net/unison
UNISON_RUN_DEPENDS=		unison:net/unison
UNISON_CONFIGURE_ENABLE=	unison-compat
WINSCP_CONFIGURE_ENABLE=	winscp-compat

post-patch:
	@${ECHO_MSG} "In addition to knobs available from the OPTIONS dialog,"
	@${ECHO_MSG} "you may set SCPONLY_DEFAULT_CHDIR to make users 'cd' to"
	@${ECHO_MSG} "this directory after authentication."
	@${REINPLACE_CMD} -e "s/-o 0 -g 0//g" ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/setup_chroot.sh ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config.h ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
