# New ports collection makefile for:   afbackup
# Date created:        15 August 2001
# Whom:                Vadim Belman <voland@catpipe.net>
#
# $FreeBSD$
#

PORTNAME=	afbackup
PORTVERSION=	3.3.5
PORTREVISION=	1
CATEGORIES?=	misc
MASTER_SITES=	ftp://ftp.vic.com/af/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	afbackup
DISTNAME=	${PORTNAME}-3.3.5
# XXX Remember to remove the comment if the actual variable is needed by someone.
#SLAVEDIRS=misc/afbackup-client misc/afbackup-server

MAINTAINER=	voland@catpipe.net

WRKSRC=		${WRKDIR}/afbackup-3.3.5
PLIST=		${WRKSRC}/pkg-plist
BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

.if ! defined(NO_DES)
USE_OPENSSL=	yes
CONFIG_WITH_DES=	--with-des
.endif
.if ! defined(NO_GUI)
BUILD_DEPENDS+=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS+=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
.else
MAKE_ARGS+=	NO_GUI=yes
.endif
USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
.if defined(NO_AUTOKEY) && defined(PACKAGE_BUILDING)
INGORE =	"cannot be build in batch mode whithout automated DES key generation"
.endif

# afmserver sometimes dumps core if compiled with optimization. A bug in gcc?
CFLAGS+=	-O0

CONFIGURE_ARGS=	--with-included-gettext \
		--libexecdir=${PREFIX}/libexec/afbackup \
		${CONFIG_WITH_DES} \
		--with-zlib \
		--with-prefixext=NO \
		--with-utilslibdir=${PREFIX}/lib/afbackup \
		--with-utilsincdir=${PREFIX}/include/afbackup \
		--with-utilsbindir=${PREFIX}/bin \
		--with-serverdir=${PREFIX} \
		--with-serverbindir=${PREFIX}/sbin \
		--with-serverconfdir=${PREFIX}/etc/afbackup \
		--with-serverlibdir=${PREFIX}/etc/afbackup \
		--with-servervardir=/var/spool/afbackup \
		--with-serverlogdir=/var/spool/afbackup \
		--with-serverconf=server.conf \
		--with-clientdir=${PREFIX} \
		--with-clientbindir=${PREFIX}/sbin \
		--with-clientconfdir=${PREFIX}/etc/afbackup \
		--with-clientlibdir=${PREFIX}/etc/afbackup \
		--with-clientvardir=/var/spool/afbackup \
		--with-clientlogdir=/var/spool/afbackup \
		--with-clientconf=client.conf \
		--with-commondir=${PREFIX} \
		--with-commondatadir=${PREFIX}/share/afbackup \
		--with-rexecdir=${PREFIX}/libexec/afbackup

CLIENTMANPAGES=
SERVERMANPAGES=
INSTALL_TARGET=
PLIST_SRC=

.if !defined(WITHOUT_CLIENT)
INSTALL_TARGET+=	install.client
CLIENTMANPAGES=		afclient.8 afrestore.8 afverify.8 \
			full_backup.8 incr_backup.8 copy_tape.8 \
			update_indexes.8 xafrestore.8 afclient.conf.8
PLIST_SRC+=		pkg-plist.client
.if !defined(NO_GUI)
PLIST_SRC+=		pkg-plist.guiclient
.endif
.if !defined(NO_DES)
PLIST_SRC+=		pkg-plist.desclient
.endif
.if defined(WITH_USERRESTORE)
INSTALL_TARGET+=	install.userrestore
.endif
.endif
.if !defined(WITHOUT_SERVER)
INSTALL_TARGET+=	install.server
SERVERMANPAGES=		afserver.8 afmserver.8 cartis.8 \
			cartready.8 label_tape.8 cart_ctl.8 \
			afserver.conf.8
PLIST_SRC+=		pkg-plist.server
.if !defined(NO_GUI)
PLIST_SRC+=		pkg-plist.guiserver
.endif
.endif
.if !defined(WITHOUT_REXECLINKS)
INSTALL_TARGET+=	install.rexeclinks
PLIST_SRC+=		pkg-plist.rexeclinks
.endif

PLIST_SRC+=		pkg-plist.l10n

MAN8=			${CLIENTMANPAGES} ${SERVERMANPAGES}

MANCOMPRESSED=		no

AFBACKUP_DOCS=		CONFIG \
			COPYING \
			Changes \
			HOWTO.FAQ.DO-DONT \
			INSTALL \
			INSTALL.utilslib \
			INTRO \
			LICENSE \
			PROGRAMS \
			README \
			UPGRADE \
			changer.conf.chio \
			changer.conf.sch-mover \
			changer.conf.test \
			changer.conf.mtx \
			changer.conf.stctl

.if defined(PACKAGE_BUILDING)
PKGINSTALL_ENV=		"NONINTERACTIVE=YES"
.else
PKGINSTALL_ENV=
.endif

.if !defined(WITHOUT_SERVER) && !defined(WITHOUT_CLIENT) \
    && !defined(WITHOUT_REXECLINKS) && !defined(NO_GUI) \
    && !defined(NO_DES) && !defined(NO_AUTOKEY)
pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	-DWITHOUT_SERVER	don't install the server part."
	@${ECHO} "	-DWITHOUT_CLIENT	don't install the client part."
	@${ECHO} "	-DWITHOUT_REXECLINKS	don't install links needed for remote execution."
	@${ECHO} "	-DWITH_USERRESTORE	allow users to use restore."
	@${ECHO} "	-DNO_GUI		build and install without TCL/TK tools."
	@${ECHO} "	-DNO_DES		build and install without DES encryption."
	@${ECHO} "	-DNO_AUTOKEY		don't autogenerate DES encryption key."
	@${ECHO} ""
.endif

pre-configure:
	@${CP} ${FILESDIR}/configure.in ${FILESDIR}/Makefile.in ${WRKSRC}
	@${CP} ${WRKSRC}/changer.conf.chio ${WRKSRC}/changer.conf

.if !defined(NO_AUTOKEY) && !defined(NO_DES)
pre-build:
	@perl -le 'print( ( "a".."z", "A".."Z", "0".."9")[ map { rand( 62)} 0..( rand( 10)+10)])' >${WRKSRC}/cryptkey
.endif

pre-install:
	@${ECHO} "==>  Creating custom pkg-plist..."
	@${RM} -rf ${PLIST}
.if !defined(NOPORTDOCS)
	@for docfile in $(AFBACKUP_DOCS:S/^/share\/doc\/${PORTNAME}\//); do ${ECHO} $$docfile >>${PLIST}; done
.endif
	@for plistfile in ${PLIST_SRC}; do ${CAT} ${FILESDIR}/$$plistfile >>${PLIST}; done
	@${CAT} ${PLIST} | perl -nle 'print unless $$lines{$$_}++' >${PLIST}.tmp
	@${CAT} ${PLIST}.tmp ${FILESDIR}/pkg-plist.fixedorder >${PLIST}
.if !defined(NOPORTDOCS)
	@${ECHO} @cwd ${PREFIX} >>${PLIST}
	@${ECHO} @dirrm share/doc/${PORTNAME} >>${PLIST}
.endif
	@$(PKGINSTALL_ENV) ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(NO_AUTOKEY)
	${INSTALL} ${COPY} -o afbackup -g operator -m 0400 ${WRKSRC}/cryptkey ${PREFIX}/etc/afbackup
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for docfile in ${AFBACKUP_DOCS}; do ${INSTALL_DATA} ${WRKSRC}/$$docfile ${DOCSDIR}; done
.endif
	@${ECHO} ""
.if !defined(NO_AUTOKEY) && !defined(NO_DES)
	@${ECHO} "-------------------------------------------------------------------"
	@${ECHO} "	A DES key has been generated for your system."
	@${ECHO} "	It can be found in ${PREFIX}/etc/afbackup/cryptkey."
	@${ECHO} "	You can change it and perhaps corresponding settings"
	@${ECHO} "	in ${PREFIX}/etc/afbackup/(server|client).conf if"
	@${ECHO} "	you want."
	@${ECHO} "-------------------------------------------------------------------"
.endif

.include <bsd.port.mk>
