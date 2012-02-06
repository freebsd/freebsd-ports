# Feed this file to mysql, e.g.,
# mysql -u root -p -v < create_hawk_user.sql

grant select,insert,update,delete
     on hawk.*
     to hawk@localhost
     identified by 'YOUR_PASSWORD_HERE';
flush privileges;
