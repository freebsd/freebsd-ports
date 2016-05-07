# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	dcc-dccd
PORTVERSION=	1.3.158
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.dcc-servers.net/dcc/source/old/ \
		ftp://ftp.dcc-servers.net/src/dcc/old/ \
		LOCAL/mat/${PORTNAME}
DISTNAME=	dcc-${PORTVERSION}

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Distributed Checksum Clearinghouse bulk email detector

.if ! defined(PACKAGE_BUILDING)
LICENSE=	DCC
LICENSE_NAME=	DCC
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	no-pkg-sell no-dist-mirror no-pkg-mirror no-dist-sell
.endif

HAS_CONFIGURE=	yes

USES=	gmake tar:Z

OPTIONS_DEFINE=	DCCIFD DCCD DCCGREY IPV6 ALT_HOME
OPTIONS_DEFAULT=	DCCIFD DCCM DCCD DCCGREY
OPTIONS_GROUP=	MILTER
OPTIONS_GROUP_MILTER=	DCCM PORTS_SENDMAIL
DCCIFD_DESC=		DCC interface daemon (for SpamAssassin etc)
DCCM_DESC=		DCC milter (for Sendmail only)
DCCD_DESC=		DCC server
DCCGREY_DESC=		DCC greylisting server
ALT_HOME_DESC=		DCC home in /var/dcc (see help)
PORTS_SENDMAIL_DESC=	Use ports Sendmail instead of base

OPTIONS_SUB=	yes

## User for DCC files and SUID binaries
#
DCCUSER?=	dcc
DCCGROUP?=	dcc

USERS=		${DCCUSER}
GROUPS=		${DCCGROUP}

PLIST_SUB+=	DCCUSER="${DCCUSER}" DCCGROUP="${DCCGROUP}"
SUB_FILES=		pkg-install pkg-message
SUB_LIST+=		WRKSRC=${WRKSRC} DCCHOME=${DCCHOME}

## Use the configure script to explicitly set the locations of all files,
## in case the standard locations have been locally overridden
## Also, use a similar hack to USES=desthack.
CONFIGURE_ARGS=	--with-uid=${DCCUSER} \
		--bindir=${PREFIX}/bin \
		--mandir=${MANPREFIX}/man \
		--with-installroot=\$${${DESTDIRNAME}} \
		--with-configsuffix=.sample \
		--with-make-cmd=${MAKE_CMD}

ALT_HOME_CONFIGURE_ON=	--libexecdir=${PREFIX}/dcc/libexec --with-cgibin=${PREFIX}/dcc/cgi-bin
DCCM_CONFIGURE_ENABLE=	dccm
DCCM_USE=	rc_subr=dccm
PORTS_SENDMAIL_BUILD_DEPENDS=	${LOCALBASE}/lib/libmilter.a:mail/libmilter
PORTS_SENDMAIL_CONFIGURE_ON=	--with-sendmail=yes
DCCIFD_CONFIGURE_ENABLE=	dccifd
DCCIFD_USE=	rc_subr=dccifd
DCCD_CONFIGURE_ENABLE=	server
IPV6_CONFIGURE_OFF=	--disable-IPv6
DCCD_USE=	rc_subr=dccd
DCCGREY_USE=	rc_subr=dccgrey

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALT_HOME}
DCCHOME=		/var/dcc
.else
DCCHOME=		${PREFIX}/dcc
.endif

CONFIGURE_ARGS+=	--homedir=${DCCHOME}

## dccm milter support
#
.if ${PORT_OPTIONS:MDCCM}

.if !exists(/usr/lib/libmilter.a) && !exists(${LOCALBASE}/lib/libmilter.a)
IGNORE=		neither base system nor Ports version of Sendmail installed, cannot build milter
.endif
.if ! ${PORT_OPTIONS:MPORTS_SENDMAIL} && !exists(/usr/lib/libmilter.a)
IGNORE=		base system Sendmail not found or too old, rebuild with WITH_PORTS_SENDMAIL=yes or WITHOUT_DCCM=yes
.endif
.if ${PORT_OPTIONS:MPORTS_SENDMAIL} && !exists(${LOCALBASE}/lib/libmilter.a)
IGNORE=		ports Sendmail not found, rebuild with WITHOUT_PORTS_SENDMAIL=yes or WITHOUT_DCCM=yes
.endif

.if ! ${PORT_OPTIONS:MPORTS_SENDMAIL}
MILTERBASE=	/usr
.else
MILTERBASE?=	${LOCALBASE}
.endif

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

post-stage:
	@${MV} ${STAGEDIR}${PREFIX}/dcc/cgi-bin/footer-dist \
		${STAGEDIR}${PREFIX}/dcc/cgi-bin/footer.sample
	@${MV} ${STAGEDIR}${PREFIX}/dcc/cgi-bin/header-dist \
		${STAGEDIR}${PREFIX}/dcc/cgi-bin/header.sample

.include <bsd.port.mk>
