PORTNAME=	portsnap
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt net
MASTER_SITES=	http://www.daemonology.net/portsnap/

MAINTAINER=	bofh@FreBSD.org
COMMENT=	Provides secure snapshots of the ports directory
WWW=		http://www.daemonology.net/portsnap/

LICENSE=	BSD2CLAUSE

SUB_FILES=		pkg-message

PLIST_FILES=	"@sample etc/portsnap.conf.sample" \
				libexec/make_index \
				sbin/portsnap \
				man/man5/portsnap.conf.5.gz \
				man/man8/portsnap.8.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500000
IGNORE=	portsnap is in base systems but will be removed from 14.0-RELEASE
.endif

post-patch:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/portsnap \
		${WRKSRC}/portsnap.conf.5 \
		${WRKSRC}/portsnap.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portsnap ${STAGEDIR}/${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/make_index ${STAGEDIR}/${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/portsnap.conf.5 ${STAGEDIR}/${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/portsnap.8 ${STAGEDIR}/${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/portsnap.conf		\
		${STAGEDIR}/${PREFIX}/etc/portsnap.conf.sample

.include <bsd.port.post.mk>
