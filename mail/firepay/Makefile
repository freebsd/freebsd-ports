# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	firepay
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Implementation of the HashCash/MIME specification

USE_BZIP2=	yes
HAS_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=yes

MAN1=		checkpayment.1 firepay.1 multiwrap.1 processmail.1 \
		sendmailpay.1 strippayment.1 takepayment.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|(unsigned char) dest-\>s\[o++\] = c|dest-\>s\[o++\] = (char) c|' \
		${WRKSRC}/firemime/firemime.c

pre-configure:
	@-${RM} -r ${WRKSRC}/firemake/*.orig
	${MV} ${WRKSRC}/conf/sendmailpay.conf ${WRKSRC}/conf/sendmailpay.conf.sample

.include <bsd.port.post.mk>
