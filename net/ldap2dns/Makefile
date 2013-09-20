# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ldap2dns
PORTVERSION=	0.4.2
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/bklang/ldap2dns/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Maintain DNS zones using an LDAP directory

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	run
USE_GMAKE=	yes
USE_OPENLDAP=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		ldap2dns.1

PORTDOCS=	*

PLIST_FILES=	bin/ldap2dns \
		bin/ldap2dnsd \
		%%DATADIR%%/axfr2ldap.pl \
		%%DATADIR%%/data2ldif.pl \
		%%DATADIR%%/ldap2dns.schema \
		%%DATADIR%%/ldap2tinydns-conf
PLIST_DIRS=	%%DATADIR%%


NO_STAGE=	yes
.include <bsd.port.options.mk>
post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		s|^LD=.*|LD=$$(CC)|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|"/etc|"${PREFIX}/etc|' ${WRKSRC}/ldap2dns.c
	@${REINPLACE_CMD} -e \
		's|^/etc|${PREFIX}/etc|' ${WRKSRC}/ldap2dns.1
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/ldap2tinydns-conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldap2dns ${PREFIX}/bin
	${LN} -sf ldap2dns ${PREFIX}/bin/ldap2dnsd
	${INSTALL_MAN} ${WRKSRC}/ldap2dns.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ldap2dns.schema ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ldap2tinydns-conf ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/axfr2ldap.pl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/data2ldif.pl ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example.ldif ${DOCSDIR}
.endif

.include <bsd.port.mk>
