# New ports collection makefile for:    p5-SyslogScan
# Date created:			26 December 1999
# Whom:	      			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	SyslogScan
PORTVERSION=	0.32
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SyslogScan
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl5 routines to parse system logs

PERL_CONFIGURE=	YES

MAN3=		SyslogScan::ByGroup.3 SyslogScan::Delivery.3 \
		SyslogScan::DeliveryIterator.3 \
		SyslogScan::SendmailLine.3 SyslogScan::SendmailLineFrom.3 \
		SyslogScan::SendmailLineTo.3 SyslogScan::SendmailUtil.3 \
		SyslogScan::Summary.3 SyslogScan::SyslogEntry.3 \
		SyslogScan::Usage.3 SyslogScan::WhereIs.3 read_mail_log.3

.include <bsd.port.mk>
