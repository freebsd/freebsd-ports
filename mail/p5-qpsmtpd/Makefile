# Created by: Zane C. Bowers
# $FreeBSD$

PORTNAME=	qpsmtpd
PORTVERSION=	0.84
PORTREVISION=	6
CATEGORIES=	mail perl5
MASTER_SITES=	http://smtpd.develooper.com/files/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible SMTP daemon written in Perl and featuring a plugin API

BUILD_DEPENDS=	spamd:${PORTSDIR}/mail/spamassassin \
		p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Net-DNS>=0.39:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Time-HiRes>0:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	MODPERL DOCS EXAMPLES
OPTIONS_DEFAULT=MODPERL
MOD_PERL_DESC=	"Apache Support via mod_perl"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMODPERL}
USE_APACHE_RUN=	22+
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}
USES=		perl5
USE_PERL5=	configure

USE_RC_SUBR=	qpsmtpd

SUB_LIST+=	PERL=${PERL}
SUB_FILES+=	pkg-message

pre-configure:
	@${RM} ${WRKSRC}/plugins/milter

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	(cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/plugins)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/config.sample/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
