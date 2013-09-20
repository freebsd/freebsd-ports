# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	im
PORTVERSION=	151
CATEGORIES=	mail
MASTER_SITES=	http://tats.haun.org/im/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of user interfaces of Email and NetNews

USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-hostname=_domain_of_your_mail_address_
MAKE_ARGS=	prefix=${PREFIX} imlibdir=${ETCDIR}

# Use RPOP instead of APOP
.if defined(WITH_RPOP)
CONFIGURE_ARGS+=	--enable-rpop
.endif

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/00* ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/man
	${INSTALL_DATA} ${WRKSRC}/man/* ${DOCSDIR}/man
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dot.im/* ${EXAMPLESDIR}
.endif

## for make PLIST (only maintainer use)
#arrange:
#	${MAKE} -DPLIST_OVERRIDE \
#	DIRRMDEPTH=1 plist

.include <bsd.port.mk>
