# Created by: Zane C. Bowers
# $FreeBSD$

PORTNAME=	qpsmtpd
PORTVERSION=	0.93
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	mail perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	noc-ports@biglist.com
COMMENT=	Flexible SMTP daemon written in Perl and featuring a plugin API

BUILD_DEPENDS=	spamd:mail/spamassassin \
		p5-Data-Dumper>=0:devel/p5-Data-Dumper \
		p5-File-Temp>=0:devel/p5-File-Temp \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-MIME-Base64>=0:converters/p5-MIME-Base64 \
		p5-Net-DNS>=0.39:dns/p5-Net-DNS \
		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
		p5-Time-HiRes>0:devel/p5-Time-HiRes
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	MODPERL DOCS EXAMPLES
OPTIONS_DEFAULT=MODPERL
MOD_PERL_DESC=	"Apache Support via mod_perl"

USE_GITHUB=	yes
GH_ACCOUNT=	smtpd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMODPERL}
USE_APACHE_RUN=	22+
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:www/mod_perl2
.endif

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

USE_RC_SUBR=	qpsmtpd

SUB_LIST+=	PERL=${PERL}
SUB_FILES+=	pkg-message

pre-configure:
	@${RM} ${WRKSRC}/plugins/milter

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	(cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/plugins)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/config.sample/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
