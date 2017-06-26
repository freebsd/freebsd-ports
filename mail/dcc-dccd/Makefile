# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	dcc-dccd
PORTVERSION=	1.3.159
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

USES=		tar:Z

OPTIONS_DEFINE=	DCCIFD DCCD DCCGREY IPV6
OPTIONS_DEFAULT=	DCCIFD DCCM DCCD DCCGREY
OPTIONS_GROUP=	MILTER
OPTIONS_GROUP_MILTER=	DCCM PORTS_MILTER
DCCIFD_DESC=		DCC interface daemon (for SpamAssassin etc)
DCCM_DESC=		DCC milter
DCCD_DESC=		DCC server
DCCGREY_DESC=		DCC greylisting server
PORTS_MILTER_DESC=	Use ports milter instead of base

OPTIONS_SUB=	yes

## User for DCC files and SUID binaries
#
DCCUSER?=	dcc
DCCGROUP?=	dcc

USERS=		${DCCUSER}
GROUPS=		${DCCGROUP}

DCCHOME=	${PREFIX}/dcc

PLIST_SUB+=	DCCUSER="${DCCUSER}" DCCGROUP="${DCCGROUP}"
SUB_FILES=		pkg-install pkg-message
SUB_LIST+=		WRKSRC=${WRKSRC} DCCHOME=${DCCHOME}

## Use the configure script to explicitly set the locations of all files,
## in case the standard locations have been locally overridden
## Also, use a similar hack to USES=desthack.
CONFIGURE_ARGS=	-q \
		--with-uid=${DCCUSER} \
		--bindir=${PREFIX}/bin \
		--mandir=${MANPREFIX}/man \
		--with-installroot=\$${${DESTDIRNAME}} \
		--with-configsuffix=.sample \
		--with-make-cmd=${MAKE_CMD} \
		--with-install-cmd=${BSD_INSTALL_PROGRAM} \
		--enable-pkg-make \
		--homedir=${DCCHOME} \
		--libexecdir=${DCCHOME}/libexec \
		--with-cgibin=${DCCHOME}/cgi-bin

CONFIGURE_ENV=	ac_cv_header_histedit_h=no	# disable libedit detection

DCCM_CONFIGURE_ENABLE=	dccm
DCCM_USE=	rc_subr=dccm
PORTS_MILTER_BUILD_DEPENDS=	${LOCALBASE}/lib/libmilter.a:mail/libmilter
PORTS_MILTER_CONFIGURE_ON=	--with-sendmail=yes
DCCIFD_CONFIGURE_ENABLE=	dccifd
DCCIFD_USE=	rc_subr=dccifd
DCCD_CONFIGURE_ENABLE=	server
IPV6_CONFIGURE_OFF=	--disable-IPv6
DCCD_USE=	rc_subr=dccd
DCCGREY_USE=	rc_subr=dccgrey

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

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/dcc/cgi-bin/footer-dist \
		${STAGEDIR}${PREFIX}/dcc/cgi-bin/footer.sample
	@${MV} ${STAGEDIR}${PREFIX}/dcc/cgi-bin/header-dist \
		${STAGEDIR}${PREFIX}/dcc/cgi-bin/header.sample
.for sf in bin/dccproc bin/cdcc dcc/libexec/dccsight dcc/libexec/check_ip_range \
	dcc/libexec/wlist dcc/libexec/ck2ip
		${STRIP_CMD} ${STAGEDIR}/${PREFIX}/${sf}
.endfor
.if ${PORT_OPTIONS:MDCCIFD} || ${PORT_OPTIONS:MDCCM}
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/dcc/libexec/dns-helper
.endif

post-install-DCCIFD-on:
.for sf in bin/dccif-test dcc/libexec/dccifd
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/${sf}
.endfor

post-install-DCCD-on:
.for sf in dcc/libexec/dump-clients dcc/libexec/dbclean \
	dcc/libexec/dblist dcc/libexec/dccd
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/${sf}
.endfor

post-install-DCCM-on:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/dcc/libexec/dccm

.include <bsd.port.mk>
