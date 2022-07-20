PORTNAME=	milter-greylist
PORTVERSION=	4.6.4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/ \
		http://fossies.org/unix/privat/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Easy-to-use greylist milter for sendmail and postfix

LICENSE=	BSD3CLAUSE

USES=		tar:tgz

MAKE_JOBS_UNSAFE=	yes

##
# Use the following quirks to choose which sendmail to use (ports or system):
#
#   WITH_MILTER_BASE=yes
# or
#   WITH_MILTER_PORT=yes
#
# If unspecified, check for an up-to-date system version but give an
# installed port preference over it.
##

OPTIONS_DEFINE=		DKIM SPF CURL LDAP P0F \
			DRAC SPAMASSASSIN \
			POSTFIX DOCS EXAMPLES GEOIP
OPTIONS_DEFAULT=	DKIM SPF CURL GEOIP
DKIM_DESC=		DKIM support
SPF_DESC=		SPF support
CURL_DESC=		curl support
P0F_DESC=		P0F support
DRAC_DESC=		DRAC support
SPAMASSASSIN_DESC=	SpamAssassin support
POSTFIX_DESC=		Use Postfix instead of Sendmail

DKIM_LIB_DEPENDS=	libopendkim.so:mail/opendkim
DKIM_USES=		ssl
P0F_RUN_DEPENDS=	p0f:net-mgmt/p0f
SPF_LIB_DEPENDS=	libspf2.so:mail/libspf2
GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

POSTFIX_CONFIGURE_ENABLE=	postfix
P0F_CONFIGURE_ENABLE=		p0f306
DRAC_CONFIGURE_ENABLE=		drac
SPAMASSASSIN_CONFIGURE_ENABLE=	spamassassin
SPAMASSASSIN_RUN_DEPENDS=	spamc:mail/spamassassin

DKIM_CONFIGURE_ON=		--with-libopendkim=${LOCALBASE}
SPF_CONFIGURE_ON=		--with-libspf2=${LOCALBASE}
GEOIP_CONFIGURE_ON=		--with-libmaxminddb=${LOCALBASE}
CURL_CONFIGURE_ON=		--with-libcurl=${LOCALBASE}
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
