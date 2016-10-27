# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	im
PORTVERSION=	153
CATEGORIES=	mail
MASTER_SITES=	http://tats.haun.org/im/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of user interfaces of Email and NetNews

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/00copyright

USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-hostname=_domain_of_your_mail_address_
CONFIGURE_ENV=	im_path_perl=${PERL}
MAKE_ARGS=	prefix=${PREFIX} imlibdir=${ETCDIR}
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES RPOP

RPOP_DESC=	Use RPOP instead of APOP
RPOP_CONFIGURE_ENABLE=	rpop

post-patch:
	@${REINPLACE_CMD} -e \
		's|SiteConfig ;|SiteConfig.sample ;|' ${WRKSRC}/Makefile.in

post-configure:
	@${LN} -sf SiteConfig ${WRKSRC}/cnf.im/SiteConfig.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/man
	${INSTALL_DATA} ${WRKSRC}/00* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/man/* ${STAGEDIR}${DOCSDIR}/man

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dot.im/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
