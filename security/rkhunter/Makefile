# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	rkhunter
PORTVERSION=	1.4.0
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Rootkit detection tool

LICENSE=	GPLv2

OPTIONS_DEFINE=	LSOF NMAP DOCS
OPTIONS_DEFAULT=LSOF

RUN_DEPENDS+=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

USE_PERL5=	yes
NO_BUILD=	yes
SUB_FILES=	415.${PORTNAME}

MAN8=		${PORTNAME}.8
MANCOMPRESSED=	no

PORTDOCS=	ACKNOWLEDGMENTS CHANGELOG FAQ LICENSE README

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLSOF}
RUN_DEPENDS+=	lsof:${PORTSDIR}/sysutils/lsof
.endif

.if ${PORT_OPTIONS:MNMAP}
RUN_DEPENDS+=	nmap:${PORTSDIR}/security/nmap
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|{SHAREDIR}/man/man8|{PREFIX}/man/man8|g' \
		${WRKSRC}/installer.sh

do-install:
	cd ${WRKSRC} && ./installer.sh --layout custom ${PREFIX} --install
	${INSTALL_MAN} ${WRKSRC}/files/${PORTNAME}.8 \
		${MAN8PREFIX}/man/man8
	@${MKDIR} ${PREFIX}/etc/periodic/security
	${INSTALL_SCRIPT} ${WRKDIR}/415.${PORTNAME} ${PREFIX}/etc/periodic/security
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/files/|} ${DOCSDIR}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/files/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
