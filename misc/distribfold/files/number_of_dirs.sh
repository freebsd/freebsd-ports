#!/bin/sh

ncpu=${1}
current_list=""

while [ ${ncpu} -gt 0 ];
do
	# update cpu count
	ncpu=$((${ncpu} - 1))

	current_list="${current_list} ${ncpu}"
done

echo ${current_list}

exit 0
