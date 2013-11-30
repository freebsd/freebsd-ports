# Created by: killer	<killer@prosalg.no>
# $FreeBSD$

PORTNAME=	pronto
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	http://muhri.net/pronto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Mail Client for Gnome/Gtk written in Perl

BUILD_DEPENDS=\
		p5-Gtk>=0:${PORTSDIR}/x11-toolkits/p5-Gtk \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-CSV>=0:${PORTSDIR}/databases/p5-DBD-CSV \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-SQL-Statement>=0:${PORTSDIR}/databases/p5-SQL-Statement \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Lingua-Ispell>=0:${PORTSDIR}/textproc/p5-Lingua-Ispell

.if defined(WITH_MYSQL)
BUILD_DEPENDS+=	p5-Mysql>=0:${PORTSDIR}/databases/p5-Mysql
.endif

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
	's,/usr/local,${PREFIX},g' ${WRKSRC}/Makefile
	@${FIND} ${WRKSRC} -name "*".bak | ${XARGS} ${RM} -f

.include <bsd.port.mk>
