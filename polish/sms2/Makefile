# Ports collection makefile for: sms
# Date created:		23 dec 2001
# Whom: 		Michal Pasternak <doc@lublin.t1.pl>
#
# $FreeBSD$
#

PORTNAME=	sms
PORTVERSION=	1.9.2m
CATEGORIES=	polish
MASTER_SITES=	http://www.ceti.pl/~miki/komputery/download/sms/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Send SMS to cellular phones in Poland (Idea, ERA, Plus)

WRKSRC=	${WRKDIR}/sms
USE_GMAKE=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
MAKE_ARGS=	CXX="${CXX}"

.if defined(NOPORTDOCS)
MAKE_ARGS+=	NOPORTDOCS=1
.endif

.if defined(WITHOUT_ADDRESSBOOK)
EXTRA_PATCHES+=	${FILESDIR}/noaddressbook.patch
.else
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
.endif

MAN1=		sms.1 smsaddr.1
MAN5=		smsrc.5

post-extract:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} -n 1 ${RM} -r

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/smsrc,${PREFIX}/etc/smsrc,' \
		${WRKSRC}/sms.h \
		${WRKSRC}/README.smsrc
	@${REINPLACE_CMD} -e 's,bash,sh,' \
		${WRKSRC}/contrib/sms-conf

post-install:
	     ${STRIP_CMD} ${PREFIX}/bin/sms

.include <bsd.port.mk>
