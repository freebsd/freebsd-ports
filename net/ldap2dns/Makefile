# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ldap2dns
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Maintain DNS zones using an LDAP directory

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	bklang

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	scripts/*.pl
USE_PERL5=	run
USE_OPENLDAP=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LDFLAGS="${LDFLAGS}"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
PLIST_FILES=	bin/ldap2dns \
		bin/ldap2dnsd \
		man/man1/ldap2dns.1.gz \
		%%DATADIR%%/axfr2ldap.pl \
		%%DATADIR%%/data2ldif.pl \
		%%DATADIR%%/ldap2dns.schema \
		%%DATADIR%%/ldap2tinydns-conf
PLIST_DIRS=	%%DATADIR%%

OPTIONS_DEFINE=		DOCS

post-patch:
	@${REINPLACE_CMD} 's|?=|=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|"/etc|"${PREFIX}/etc|' ${WRKSRC}/ldap2dns.c
	@${REINPLACE_CMD} -e \
		's|^/etc|${PREFIX}/etc|' ${WRKSRC}/ldap2dns.1
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/ldap2tinydns-conf

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ldap2dns \
		${STAGEDIR}${PREFIX}/bin)
	${LN} -sf ldap2dns ${STAGEDIR}${PREFIX}/bin/ldap2dnsd
	(cd ${WRKSRC} && ${INSTALL_MAN} ldap2dns.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ldap2dns.schema ldap2tinydns-conf \
		${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/scripts && ${INSTALL_SCRIPT} axfr2ldap.pl data2ldif.pl \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} README.html example.ldif \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
