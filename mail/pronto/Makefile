# New ports collection makefile for:	pronto
# Date created:		15 March 2001
# Whom:			killer	<killer@prosalg.no>
#
# $FreeBSD$

PORTNAME=	pronto
PORTVERSION=	2.2.5
CATEGORIES=	mail perl5
MASTER_SITES=	http://muhri.net/pronto/

MAINTAINER=	killer@prosalg.no

BUILD_DEPENDS=\
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/DBD/CSV.pm:${PORTSDIR}/databases/p5-DBD-CSV \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Lingua/Ispell.pm:${PORTSDIR}/textproc/p5-Lingua-Ispell

.if defined(WITH_HTML)
BUILD_DEPENDS+= ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk/XmHTML.pm:${PORTSDIR}/x11-toolkits/p5-GtkXmHTML
.endif

.if defined(WITH_MYSQL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.mk>
