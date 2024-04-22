PORTNAME=	nsca-ng
PORTVERSION=	1.6
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	alexander@sulfrian.net
COMMENT=	Nagios Service Check Acceptor
WWW=		https://github.com/weiss/nsca-ng

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libev.so:devel/libev
.if !defined(PKGNAMESUFFIX)
LIB_DEPENDS+=	libconfuse.so:devel/libconfuse
.endif

USES=		ssl autoreconf
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--localstatedir=/var/spool/nagios
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

USE_GITHUB=	true
GH_ACCOUNT=	weiss

.if !defined(PKGNAMESUFFIX)
USE_RC_SUBR=	nsca-ng
CONFIGURE_ARGS+=	--enable-server
.endif

CONFLICTS?=	nsca-2.* nsca27-2.*

PORTDOCS=	NEWS COPYING README PROTOCOL TODO

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE+=	requires PSK which is unsupported by the selected LibreSSL
.endif

post-install:
.if defined(PKGNAMESUFFIX)
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios/
	${LN} -s ${PREFIX}/sbin/send_nsca ${STAGEDIR}${PREFIX}/libexec/nagios/send_nsca

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

	cd ${STAGEDIR}${PREFIX}/etc && ${MV} send_nsca.cfg send_nsca.cfg.sample
	# remove files not used here
	cd ${STAGEDIR}${PREFIX} && ${RM} share/man/man8/nsca-ng.8 share/man/man5/nsca-ng.cfg.5
.else
	cd ${STAGEDIR}${PREFIX}/etc && ${MV} nsca-ng.cfg nsca-ng.cfg.sample
	# remove files not used here
	cd ${STAGEDIR}${PREFIX} && ${RM} etc/send_nsca.cfg share/man/man5/send_nsca.cfg.5 \
		share/man/man8/send_nsca.8 sbin/send_nsca
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
