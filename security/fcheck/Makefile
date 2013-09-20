# Created by: Lars Engels <lme@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fcheck
PORTVERSION=	2.07.59
CATEGORIES=	security
MASTER_SITES=	http://www.sourcefiles.org/Networking/Security/Intrusion_Detection/ \
		http://bsd-geek.de/FreeBSD/distfiles/
DISTNAME=	FCheck_${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Intrusion detection and Policy enforcement / auditing software

WRKSRC=	${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PLIST_FILES=	sbin/${PORTNAME} etc/${PORTNAME}.cfg.sample
NO_BUILD=	YES
USES=		perl5

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PREFIX}/bin/perl|' \
		-e 's|/usr/local/admtools/conf/|${PREFIX}/etc/|' ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's|/usr/local/admtools/|/var/${PORTNAME}/|' \
		-e 's|/bin/file|/usr/bin/file|' -e 's|/bin/cksum|/sbin/md5|' \
		${WRKSRC}/${PORTNAME}.cfg

do-install:
	${MKDIR} /var/${PORTNAME}
	${MKDIR} /var/${PORTNAME}/logs
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg ${PREFIX}/etc/${PORTNAME}.cfg.sample

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/install ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
