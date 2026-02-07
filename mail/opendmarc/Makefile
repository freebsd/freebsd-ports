PORTNAME=	opendmarc
DISTVERSION=	1.4.2
PORTREVISION=	4
CATEGORIES=	mail security
MASTER_SITES=	GH

MAINTAINER=	freebsd@gushi.org
COMMENT=	DMARC library and milter implementation
WWW=		http://www.trusteddomain.org/opendmarc.html

LICENSE=			BSD3CLAUSE SENDMAIL
LICENSE_COMB=			multi
LICENSE_GROUPS_SENDMAIL=	FSF OSI
LICENSE_NAME_SENDMAIL=		Sendmail Open Source License
LICENSE_FILE_SENDMAIL=		${WRKSRC}/LICENSE.Sendmail
LICENSE_PERMS_SENDMAIL=		dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	p5-Switch>=0:lang/p5-Switch \
		p5-DBI>=0:databases/p5-DBI \
		${DBD_MYSQL} \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		public_suffix_list>=0:dns/public_suffix_list

USES=		cpe libtool mysql perl5 shebangfix autoreconf
CPE_VENDOR=	trusteddomain
USE_GITHUB=	yes
GH_ACCOUNT=	trusteddomainproject
GH_PROJECT=	OpenDMARC
GH_TAGNAME=	rel-${PORTNAME}-${DISTVERSION:S/./-/g}
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	reports/opendmarc-expire.in \
		reports/opendmarc-import.in \
		reports/opendmarc-params.in \
		reports/opendmarc-reports.in

GNU_CONFIGURE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		SPF DOCS
OPTIONS_DEFAULT=	SPF

SPF_DESC=		Enable support for SPF record checking

SPF_LIB_DEPENDS=	libspf2.so:mail/libspf2
SPF_CONFIGURE_ON=	--with-spf \
			--with-spf2-include=${LOCALBASE}/include/spf2 \
			--with-spf2-lib=${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"
CONFIGURE_ARGS+=	--with-milter=${MILTERBASE}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/opendmarc/opendmarc.conf.sample

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_DATA} \
		${WRKSRC}/opendmarc/opendmarc.conf.sample ${STAGEDIR}${PREFIX}/etc/mail
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopendmarc.so.2

.include <bsd.port.post.mk>
