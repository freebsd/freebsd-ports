# Created by: Cyril Guibourg
# $FreeBSD$

PORTNAME=	milter-greylist
PORTVERSION=	4.4.3
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/ \
		http://fossies.org/unix/privat/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Easy-to-use greylist milter for sendmail and postfix

LICENSE=	BSD3CLAUSE

CONFLICTS=	milter-greylist-devel-[1-9]*.*
PKGMESSAGE=	${WRKDIR}/pkg-message

MAKE_JOBS_UNSAFE=	yes

USES=		tar:tgz

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

OPTIONS_DEFINE=		SPF GEOIP CURL DKIM LDAP P0F POSTFIX DOCS EXAMPLES
SPF_DESC=		SPF support
DKIM_DESC=		DKIM support
CURL_DESC=		curl support
P0F_DESC=		P0F support
POSTFIX_DESC=		Use Postfix instead of Sendmail

P0F_RUN_DEPENDS=	p0f:${PORTSDIR}/net-mgmt/p0f
SPF_LIB_DEPENDS=	libspf2.so:${PORTSDIR}/mail/libspf2
CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
GEOIP_LIB_DEPENDS=	libGeoIP.so:${PORTSDIR}/net/GeoIP
DKIM_LIB_DEPENDS=	libdkim.so:${PORTSDIR}/mail/libdkim

POSTFIX_CONFIGURE_ENABLE=	postfix
POSTFIX_LDFLAGS_OFF=		${SENDMAIL_LDFLAGS}
POSTFIX_LIBS_OFF=		${SENDMAIL_LDADD}

P0F_CONFIGURE_ENABLE=		p0f306

DKIM_CONFIGURE_WITH=		--with-libdkim=${LOCALBASE}
SPF_CONFIGURE_WITH=		--with-libspf2=${LOCALBASE}
GEOIP__CONFIGURE_WITH=		--with-libGeoIP=${LOCALBASE}
CURL_CONFIGURE_WITH=		--with-libcurl=${LOCALBASE}
LDAP_CONFIGURE_ON=		--with-openldap=${LOCALBASE}
LDAP_LDFLAGS=			-L${LOCALBASE}/lib
LDAP_USE=			OPENLDAP=yes

.include <bsd.port.options.mk>

LIBS+=		-lpthread

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-user=mailnull \
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
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_MAN} ${WRKSRC}/greylist.conf.5 \
		${STAGEDIR}${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/milter-greylist.8 \
		${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_PROGRAM} ${WRKSRC}/milter-greylist \
		${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
		${STAGEDIR}${PREFIX}/etc/mail/greylist.conf.sample
	@${MKDIR} ${STAGEDIR}/var/milter-greylist

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/greylist.conf ${STAGEDIR}${EXAMPLESDIR}/
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.include <bsd.port.mk>
