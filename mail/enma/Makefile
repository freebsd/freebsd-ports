# New ports collection makefile for:	enma
# Date created:				7 Sep 2008
# Whom:					Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	enma
PORTVERSION=	1.0.0
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A sender authentication milter supporting SPF and Sender ID

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/dns/bind94:fetch \
		${NONEXISTENT}:${PORTSDIR}/mail/sendmail:fetch

.if defined(WITH_POSTFIX_MILTER) || defined(WITH_POSTFIX) || defined(WITH_POSTFIX_CURRENT)
CONF_SUB=	${REINPLACE_CMD} -e '/milter\.postfix/s/false/true/' ${WRKSRC}/enma/etc/enma.conf.sample
.if defined(WITH_POSTFIX_CURRENT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix-current
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix
.endif
.endif

BIND_SRC_CMD=	cd ${PORTSDIR}/dns/bind94 && ${MAKE} -V DISTFILES | ${CUT} -d ' ' -f 1
SENDMAIL_SRC_CMD=	cd ${PORTSDIR}/mail/sendmail && make -V DISTFILES

USE_RC_SUBR=	milter-enma
USE_GMAKE=	yes
MAN1=		enma.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/enma bin/sidfquery etc/enma.conf.sample
PORTDOCS=	ChangeLog INSTALL LICENSE README TODO
SUB_FILES=	milter-enma

.include <bsd.port.pre.mk>

pre-configure:
	${LN} -s ${DISTDIR}/$$(${BIND_SRC_CMD}) ${WRKSRC}/build
	${LN} -s ${DISTDIR}/$$(${SENDMAIL_SRC_CMD}) ${WRKSRC}/build
	$$(${CONF_SUB})

do-build:
	cd ${WRKSRC}/build && ./build_all.sh --prefix=${PREFIX}

do-install:
	cd ${WRKSRC}/build && ./build_all.sh install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
