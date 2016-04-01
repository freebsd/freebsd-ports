# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	slapd-cyrus
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	mail net
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	Slapd-Backend-Cyrus-${PORTVERSION}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Slapd backend to translate DIT into Cyrus configuration

BUILD_DEPENDS=	cyrus-imapd24>=0:mail/cyrus-imapd24 \
		p5-BerkeleyDB>=0:databases/p5-BerkeleyDB \
		p5-Class-Accessor-Lvalue>=0:devel/p5-Class-Accessor-Lvalue \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Test-Class>=0:devel/p5-Test-Class \
		p5-perl-ldap>=0:net/p5-perl-ldap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

PLIST_SUB=	SITE_PERL_REL=${SITE_PERL_REL} \
		DOCS_DIR_REL=${DOCSDIR_REL}

PORTDOCS=	slapd-cyrus.conf.sample

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} -m 0444 ${WRKSRC}/t/etc/slapd.conf.dist \
		${STAGEDIR}${DOCSDIR}/slapd-cyrus.conf.sample
	cd ${WRKSRC}/lib && ${PAX} -r -w . ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

.include <bsd.port.mk>
