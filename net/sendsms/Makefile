# New ports collection makefile for:	www/sendsms
# Date created:				2005-12-17
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#
# $Tecnik: ports/www/sendsms/Makefile,v 1.1 2005/12/17 03:27:10 itetcu Exp $

PORTNAME=	sendsms
PORTVERSION=	0.2.3
CATEGORIES=	net perl5
MASTER_SITES=	http://caspian.dotconf.net/menu/Software/SendSMS/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/
DISTNAME=	sendSMS.pl
EXTRACT_SUFX=	.gz

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Simple perl command-line utility to send SMS via from on provider site

EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${PORTNAME}

PLIST_FILES=	bin/sendsms

CONFLICTS=	smstools-[0-9]*

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5_RUN=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL},g" ${WRKSRC}/${PORTNAME}

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
