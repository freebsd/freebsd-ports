# New ports collection makefile for:	slapd-cyrus
# Date created:				Wed 16 Sep 2009
# Whom:					Alexey V. Degtyarev
#
# $FreeBSD$
#

PORTNAME=	slapd-cyrus
PORTVERSION=	0.01
CATEGORIES=	mail net
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	Slapd-Backend-Cyrus-${PORTVERSION}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Slapd backend to translate DIT into Cyrus configuration

BUILD_DEPENDS=	cyrus-imapd>=0:${PORTSDIR}/mail/cyrus-imapd23 \
		p5-BerkeleyDB>=0:${PORTSDIR}/databases/p5-BerkeleyDB \
		p5-Class-Accessor-Lvalue>=0:${PORTSDIR}/devel/p5-Class-Accessor-Lvalue \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Test-Class>=0:${PORTSDIR}/devel/p5-Test-Class \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	5.10+

PERL_MODBUILD=	yes

PLIST_SUB=	SITE_PERL_REL=${SITE_PERL_REL} \
		DOCS_DIR_REL=${DOCSDIR_REL}

.if !defined(NOPORTDOCS)
PORTDOCS=	slapd-cyrus.conf

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} -m 0444 ${WRKSRC}/t/etc/slapd.conf.dist \
		${DOCSDIR}/slapd-cyrus.conf
.endif

do-install:
	${MKDIR} ${SITE_PERL}
	cd ${WRKSRC}/lib && ${PAX} -r -w . ${SITE_PERL}

.include <bsd.port.mk>
