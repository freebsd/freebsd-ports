# Created by: Cyril Guibourg
# $FreeBSD$

PORTNAME=	milter-greylist
PORTVERSION=	4.6.a1
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/ \
		http://fossies.org/unix/privat/ \
		ftp://ftpmirror.uk/freebsd-ports/milter-greylist/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-4.6a1

MAINTAINER= 	freebsd-ports@dan.me.uk
COMMENT=	Unstable (dev) greylist milter for sendmail and postfix

LICENSE=	BSD3CLAUSE

CONFLICTS=	milter-greylist-[0-9]*.*
PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		tar:tgz

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DKIM SPF GEOIP CURL LDAP P0F POSTFIX DOCS EXAMPLES
OPTIONS_DEFAULT=DKIM SPF GEOIP CURL EXAMPLES
DKIM_DESC=	Include DKIM support
SPF_DESC=	Include SPF support
CURL_DESC=	curl support
P0F_DESC=	P0F support
POSTFIX_DESC=	Use Postfix instead of Sendmail

DKIM_BUILD_DEPENDS+=	opendkim>=0:mail/opendkim
P0F_RUN_DEPENDS+=	p0f:net-mgmt/p0f
SPF_BUILD_DEPENDS=	libspf2>=1.2.5:mail/libspf2
CURL_BUILD_DEPENDS+=	curl>=7.18:ftp/curl
GEOIP_BUILD_DEPENDS=	GeoIP>=1.4.4:net/GeoIP

POSTFIX_CONFIGURE_ENABLE=	postfix
P0F_CONFIGURE_ENABLE=		p0f306

.include <bsd.port.options.mk>

##
# Use the following quirks to choose which sendmail to use (ports or system):
#
#   WITH_SENDMAIL_BASE=yes
# or
#   WITH_SENDMAIL_PORT=yes
#
# If unspecified, check for an up-to-date system version but give an
# installed port preference over it.
##

.if ${PORT_OPTIONS:MDKIM}
CONFIGURE_ARGS+=	--with-libopendkim=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MSPF}
CONFIGURE_ARGS+=	--with-libspf2=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MGEOIP}
CONFIGURE_ARGS+=	--with-libGeoIP=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MCURL}
CONFIGURE_ARGS+=	--with-libcurl=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MLDAP}
# We can't use LDAP_CONFIGURE_WITH because configure script is buggy
CONFIGURE_ARGS+=	--with-openldap
USE_OPENLDAP=		yes
.endif

.if ! ${PORT_OPTIONS:MPOSTFIX}
LDFLAGS+=	${SENDMAIL_LDFLAGS}
LIBS+=		${SENDMAIL_LDADD}
.endif

LIBS+=		-lpthread

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-user=mailnull \
		--with-libmilter=${MILTERBASE} \
		--enable-dnsrbl \
		--with-thread-safe-resolver \
		--with-dumpfile=/var/milter-greylist/greylist.db

ALL_TARGET=	milter-greylist
SUB_FILES+=	pkg-message
USE_RC_SUBR=	milter-greylist
PORTDOCS=	README
PORTEXAMPLES=	greylist.conf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_MAN} ${WRKSRC}/greylist.conf.5 \
		${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/milter-greylist.8 \
		${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/milter-greylist \
		${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
		${STAGEDIR}${PREFIX}/etc/mail/greylist.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/greylist.conf ${STAGEDIR}${EXAMPLESDIR}
.endif
	@${MKDIR} ${STAGEDIR}/var/milter-greylist

.include "${.CURDIR}/../sendmail/bsd.milter.mk"
.include <bsd.port.mk>
