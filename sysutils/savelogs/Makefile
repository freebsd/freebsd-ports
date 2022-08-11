PORTNAME=	savelogs
PORTVERSION=	1.98
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SCOTTW

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Save log files in a nice way

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/savelogs.conf.sample ${STAGEDIR}${PREFIX}/etc/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/savelogs.conf.lint ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
