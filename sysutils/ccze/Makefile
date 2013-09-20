# $FreeBSD$

PORTNAME=	ccze
PORTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://falafel.200ok.org/distfiles/ccze/ \
		http://200ok.org/distfiles/ccze/

MAINTAINER=	ecu@200ok.org
COMMENT=	Fast log colorizer

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		ccze.1 ccze-cssdump.1
MAN7=		ccze-plugin.7

NO_STAGE=	yes
post-install:
	@${WRKSRC}/src/ccze-dump > ${PREFIX}/etc/cczerc-sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
.endif

.include <bsd.port.mk>
