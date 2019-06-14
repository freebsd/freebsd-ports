# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	dcc-dccd
PORTVERSION=	2.3.165
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	https://www.dcc-servers.net/dcc/source/old/
DISTNAME=	dcc-${PORTVERSION}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Distributed Checksum Clearinghouse bulk email detector

LICENSE=	DCC
LICENSE_NAME=	DCC
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	no-pkg-sell no-dist-mirror no-pkg-mirror no-dist-sell

USES=		tar:Z

USERS=		${DCCUSER}
GROUPS=		${DCCGROUP}

PLIST_SUB=	DCCDATA="${DCCDATA}" DCCUSER="${DCCUSER}" DCCGROUP="${DCCGROUP}"
SUB_FILES=	pkg-install pkg-message
SUB_LIST=	DCCDATA="${DCCDATA}" DCCUSER="${DCCUSER}" DCCGROUP="${DCCGROUP}" WRKSRC=${WRKSRC} DCCHOME=${DCCHOME}

## Use the configure script to explicitly set the locations of all files,
## in case the standard locations have been locally overridden
## Also, use a similar hack to USES=desthack.
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-q \
		--without-DCC-MD5 \
		--with-uid=${DCCUSER} \
		--bindir=${PREFIX}/bin \
		--mandir=${MANPREFIX}/man \
		--with-installroot=\$${${DESTDIRNAME}} \
		--with-configsuffix=.sample \
		--with-make-cmd=${MAKE_CMD} \
		--with-install-cmd=${BSD_INSTALL_PROGRAM} \
		--enable-pkg-make \
		--homedir=${DCCDATA} \
		--libexecdir=${PREFIX}/libexec \
		--with-cgibin=${DCCHOME}/cgi-bin

CONFIGURE_ENV=	ac_cv_header_histedit_h=no	# disable libedit detection

OPTIONS_DEFINE=		DCCIFD DCCD DCCGREY IPV6
OPTIONS_DEFAULT=	DCCIFD DCCM DCCD DCCGREY
OPTIONS_GROUP=		MILTER
OPTIONS_GROUP_MILTER=	DCCM PORTS_MILTER
OPTIONS_SUB=		yes

DCCD_DESC=		DCC server
DCCGREY_DESC=		DCC greylisting server
DCCIFD_DESC=		DCC interface daemon (for SpamAssassin etc)
DCCM_DESC=		DCC milter
PORTS_MILTER_DESC=	Use ports milter instead of base

DCCD_USE=			rc_subr=dccd
DCCD_CONFIGURE_ENABLE=		server
DCCGREY_USE=			rc_subr=dccgrey
DCCIFD_USE=			rc_subr=dccifd
DCCIFD_CONFIGURE_ENABLE=	dccifd
DCCM_USE=			rc_subr=dccm
DCCM_CONFIGURE_ENABLE=		dccm
IPV6_CONFIGURE_OFF=		--disable-IPv6
PORTS_MILTER_BUILD_DEPENDS=	${LOCALBASE}/lib/libmilter.a:mail/libmilter
PORTS_MILTER_CONFIGURE_ON=	--with-sendmail=yes

## User for DCC files and SUID binaries
#
DCCUSER?=	dcc
DCCGROUP?=	dcc

DCCHOME=	${PREFIX}/dcc
DCCDATA=	/var/db/dcc

.include <bsd.port.options.mk>

## dccm milter support
#
.if ${PORT_OPTIONS:MPORTS_MILTER}
MILTERBASE?=	${LOCALBASE}

MILTERINC=	${MILTERBASE}/include
MILTERLIB=	${MILTERBASE}/lib

CPPFLAGS+=	-I${MILTERINC}
CFLAGS+=	-I${MILTERINC}
LDFLAGS+=	-L${MILTERLIB}
.endif

.if ${PORT_OPTIONS:MDCCIFD} || ${PORT_OPTIONS:MDCCM}
PLIST_SUB+=	IFD_MILT=""
.else
PLIST_SUB+=	IFD_MILT="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,md5.c ,,' ${WRKSRC}/clntlib/Makefile.in
	${REINPLACE_CMD} -e 's,^\(BININSTALL.*\),\1 -s,p'	\
			-e 's,^BIN\(INSTALL\s*=\s*.*\) -s$$,SCRIPT\1,' ${WRKSRC}/Makefile.inc.in
	${REINPLACE_CMD} -e 's,BININSTALL,SCRIPTINSTALL,g'	\
			${WRKSRC}/homedir/Makefile.in ${WRKSRC}/misc/Makefile.in

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/dcc/cgi-bin/footer-dist \
		${STAGEDIR}${PREFIX}/dcc/cgi-bin/footer.sample
	@${MV} ${STAGEDIR}${PREFIX}/dcc/cgi-bin/header-dist \
		${STAGEDIR}${PREFIX}/dcc/cgi-bin/header.sample

.include <bsd.port.mk>
