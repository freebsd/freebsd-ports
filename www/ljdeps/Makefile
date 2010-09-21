# New ports collection makefile for:	www/ljdeps
# Date created:		23 July 2002
# Whom:			Ryan T. Dean <rtdean@cytherianage.net>
#
# $FreeBSD$
#

PORTNAME=	ljdeps
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	# Undefined
DISTFILES=	# Undefined

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A meta-port to install all the perl modules used by LiveJournal

RUN_DEPENDS=	${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Time/DaysInMonth.pm:${PORTSDIR}/devel/p5-Time-modules \
		${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil \
		${SITE_PERL}/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/Proc/ProcessTable.pm:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
		${SITE_PERL}/Unicode/MapUTF8.pm:${PORTSDIR}/converters/p5-Unicode-MapUTF8

EXTRACT_ONLY=	# Empty
NO_BUILD=	yes
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

do-install:	# Empty

.include <bsd.port.post.mk>
