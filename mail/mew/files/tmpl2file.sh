#!/bin/sh

for f in ${TMPL_FILES}; do
	sed \
		-e "s,%%EMACS_CMD%%,${EMACS_CMD},g" \
		-e "s,%%EMACS_PORTSDIR%%,${EMACS_PORTSDIR},g" \
		-e "s,%%PKGNAME%%,${PKGNAME},g" \
		-e "s,%%EMACS_PORT_NAME%%,${EMACS_PORT_NAME},g" \
		-e "s,%%PORTNAME%%,${PORTNAME},g" \
		-e "s,%%ELISPDIR%%,${ELISPDIR},g" \
		-e "s,%%INFODIR%%,${INFODIR},g" \
		-e "s,%%ETCDIR%%,${ETCDIR},g" \
		< ${FILESDIR}/${f}.tmpl > ${WRKTMPDIR}/${f}
done
