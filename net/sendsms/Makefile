# New ports collection makefile for:	www/sendsms
# Date created:				2005-12-17
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $Tecnik: ports/www/sendsms/Makefile,v 1.3 2006/05/12 12:15:34 itetcu Exp $
# $FreeBSD$

PORTNAME=	sendsms
PORTVERSION=	0.2.4
CATEGORIES=	net perl5
MASTER_SITES=	http://caspian.dotconf.net/menu/Software/SendSMS/ \
		http://sce-tindy.tecnik93.com/FreeBSD/ports/${PORTNAME}/sources/
DISTNAME=	sendSMS.pl
EXTRACT_SUFX=	.gz

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Simple perl command-line utility to send SMS via from on provider site

EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${PORTNAME}

PLIST_FILES=	bin/sendsms

CONFLICTS=	smstools-[0-9]*

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL},g" ${WRKSRC}/${PORTNAME}

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
